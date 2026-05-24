#include<stdio.h>
int s[10],x[10],d;
void sumofsub(int,int,int);

void main()
{
int n,i,sum=0;

printf("\nEnter the size of the set:");
scanf("%d",&n);

printf("\nEnter the set in increasing order:\n");

for(i=1;i<=n;i++)
scanf("%d",&s[i]);

printf("\nEnter the value of d:\n");
scanf("%d",&d);

for(i=1;i<=n;i++)
sum=sum+s[i];

if(sum<d||s[1]>d)
{
printf("\nNo subset possible");
}
else
{
sumofsub(0,1,sum);
}
}

void sumofsub(int m,int k,int r)
{
int i;

x[k]=1;

if((m+s[k])==d)
{
printf("Subset is:\n");

for(i=1;i<=k;i++)
{
if(x[i]==1)
printf("%d\t",s[i]);
}

printf("\n");
}
else if((m+s[k]+s[k+1])<=d)
{
sumofsub(m+s[k],k+1,r-s[k]);
}

if((m+r-s[k]>=d)&&(m+s[k+1]<=d))
{
x[k]=0;
sumofsub(m,k+1,r-s[k]);
}
}