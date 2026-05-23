#include<stdio.h>
int cost[10][10],parent[10],n;
int find_parent(int);

void main(){
    int i,j,u,v,p,q;
    int ne=1,min=999,total_cost=0;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
    scanf("%d",&cost[i][j]);
    if(cost[i][j]==0)
    cost[i][j]=999;
    }
    for(i=1;i<=n;i++)
    parent[i]=-1;
    printf("Minimum cost Spanning Tree is :\n");
    while(ne<n){
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(cost[i][j]<min){
        min=cost[i][j];
        u=i;
        v=j;
    }
    p=find_parent(u);
    q=find_parent(v);
    if(p!=q){
        parent[v]=p;
        printf("%d edge from %d to %d = %d\n",ne,u,v,min);
        ne++;
        total_cost+=cost[u][v];
    }
    cost[u][v]=cost[v][u]=999;
    min=999;
    }
    printf("The total cost of spanning Tree is:%d\n",total_cost);
}
int find_parent(int x){
    while(parent[x]!=-1)
        x=parent[x];
    return x;
}
