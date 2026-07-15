#include<stdio.h>
int cost[10][10],parent[10],n;

int find_parent(int x);

void main(){
    int i,j,u,v,p,q,ne=1,min=999,total_cost=0;
    printf("Enter the size of the adjacency matrix:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
    scanf("%d",&cost[i][j]);
    if(cost[i][j]==0)
    cost[i][j]=999;
    }
    for(i=1;i<=n;i++)
    parent[i]=-1;
    printf("The minimum cost spanning tree is :\n");
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
            printf("%d edge from %d to %d =%d\n",ne,u,v,min);
            total_cost+=cost[u][v];
            parent[v]=p;
            ne++;
        }
        cost[u][v]=cost[v][u]=999;
        min=999;

    }
    printf("Total cost matrix :%d\n",total_cost);
}

int find_parent(int x){
    while(parent[x]!=-1)
    x=parent[x];
    return x;
}
/*
Output:
Enter the size of the adjacency matrix:
5
Enter the adjacency matrix:
0 5 0 1 0 
5 0 0 3 0 
0 0 0 4 6
1 3 4 0 2
0 0 6 2 0
The minimum cost spanning tree is :
1 edge from 1 to 4 =1
2 edge from 4 to 5 =2
3 edge from 2 to 4 =3
4 edge from 3 to 4 =4
Total cost matrix :10
*/