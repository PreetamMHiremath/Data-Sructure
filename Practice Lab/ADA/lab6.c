#include<stdio.h>

int cost[10][10],start,ne=1,n,i,j,u,v,visited[10],min=999,total_cost;
void main(){
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        cost[i][j]=999;
    }
    printf("Enter the starting vertex:\n");
    scanf("%d",&start);
    visited[start]=1;
    printf("Minimum Cost spanning Tree is :\n");
    while(ne<n){
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(cost[i][j]<min && (visited[i]==1 && visited[j]==0)){
                min=cost[i][j];
                u=i;
                v=j;
            }
            printf("%d edge from %d to %d =%d\n",ne,u,v,min);
            ne++;
            total_cost+=cost[u][v];
            cost[u][v]=cost[v][u]=999;
            visited[v]=1;
            min=999;
    }
    printf("Total cost of the span Tree is %d",total_cost);
}