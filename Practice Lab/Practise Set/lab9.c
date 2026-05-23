#include<stdio.h>
#include<stdlib.h>

int s[10],a[10][10],n;

void dfs(int u){
    int v;
    s[u]=1;
    printf("%d",u);
    for(v=0;v<n;v++){
        if(a[u][v]==1 && s[v]==0){
            dfs(v);
        }
    }
}

void main(){
    int i,j,source;
    printf("Enter the Number of Nodes in the Graph:\n");
    scanf("%d",&n);

    printf("Enter the adjecency Matrix:\n");
    for ( i = 0; i < n; i++)
    for ( j = 0; j < n; j++)
    scanf("%d",&a[i][j]);
    
    printf("Enter the Source Node in the graph:\n");
    scanf("%d",&source);

    printf("The Nodes Reachable From %d:",source);
    dfs(source);
}   