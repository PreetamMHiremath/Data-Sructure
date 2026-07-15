#include<stdio.h>

int s[10],x[10],d;

void sumofsub(int m,int k,int r);

void main(){
    int n,i,sum=0;
    printf("Enter the size of the set :\n");
    scanf("%d",&n);
    printf("Enter the set in the increasing order:\n");
    for(i=1;i<=n;i++){
    scanf("%d",&s[i]);
    sum+=s[i];
    }
    printf("Enter the value of d:\n");
    scanf("%d",&d);
    if(sum<d || s[1]>d)
    printf("No subset is possible.");
    else{
    sumofsub(0,1,sum);
}
}

void sumofsub(int m,int k,int r){
    int i;
    x[k]=1;
    //First condition
    if(m+s[k]==d){
    printf("Subset is :\n");
    for ( i = 1; i <=k; i++)
    {
        if(x[i]==1)
        printf("%d\t",s[i]);
    }
    printf("\n");
    }
    //second condition
    else if(m+s[k]+s[k+1]<=d)
    sumofsub(m+s[k],k+1,r-s[k]);
    if(m+r-s[k]>=d && m+s[k+1]<=d){
        // this is important in the order if mistake it will gives the wrong result
        x[k]=0;
        sumofsub(m,k+1,r-s[k]);
    }

}