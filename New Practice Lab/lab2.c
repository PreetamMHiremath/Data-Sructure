#include<stdio.h>
int cost[10][10],visited[10],n;



void main(){
    int i,j,u,v,start,ne=1,min=999,total_cost=0;
    printf("Enter the size of the adjacency matrix:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
    scanf("%d",&cost[i][j]);
    if(cost[i][j]==0)
    cost[i][j]=999;
    }
    printf("Enter the Starting vertex:\n");
    scanf("%d",&start);
    visited[start]=1;
    printf("The minimum cost spanning tree is :\n");
    while(ne<n){
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<min && visited[i]==1 && visited[j]==0){
            min=cost[i][j];
            u=i;
            v=j;
        }
        printf("%d edge from %d to %d =%d\n",ne,u,v,min);
        total_cost+=cost[u][v];
        ne++;
        cost[u][v]=cost[v][u]=999;
        min=999;
        visited[v]=1;
    }
    printf("Total cost matrix :%d\n",total_cost);
}

