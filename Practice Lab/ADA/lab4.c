#include<stdio.h>
void SourceRemoval();
int FindSource();
int arr[10][10],indegree[10], n, source;
int main()
{
int i, j;
printf("enter the number of vertices\n");
scanf("%d", &n);
printf("\n enter the adjacency matrix \n");
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
scanf("%d", &arr[i][j]);
for(j=1; j<=n; j++)
for(i=1; i<=n; i++)
if(arr[i][j] == 1)
indegree[j]++;
source = FindSource();
if(source != -1)
{
printf("Topological Sorting using Source Removal method: \n");
SourceRemoval();
printf("\n");
}
else
printf("Topological Sorting Not Possible \n");

}
int FindSource()
{
int i;
for(i=1; i<=n; i++)
if(indegree[i]==0)
return i;
return -1;
}
void SourceRemoval()
{
int j;
while(source != -1)
{
printf("%d\t", source);
indegree[source]=-1;
for(j=1; j<=n; j++)
if(arr[source][j]==1)
indegree[j]--;
source = FindSource();
}
}