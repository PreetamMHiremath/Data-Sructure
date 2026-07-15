#include<stdio.h>
int min(int,int);
int cost[10][10],i,j,k,n;
void main(){
    printf("Enter the Number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix(999 for infinte):\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&cost[i][j]);
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
    printf("The all pair Shortest path is :\n");
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
        printf("%d\t",cost[i][j]);
        printf("\n");
    }
}
int min(int a,int b){
    return a<b?a:b;
}
