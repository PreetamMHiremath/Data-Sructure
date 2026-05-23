#include<stdio.h>
int s[10],a[10][10],n;

void dfs(int u){
    int v;
    s[u]=1;
    printf("%d\n",u);
    for(v=0;v<n;v++){
        if(a[u][v]==1 && s[v]==0)
            dfs(v);
    }
}
void main(){
    int i,j,source;
    printf("Enter the number of Nodes:\n");
    scanf("%d",&n);

    printf("Enter the adjacency Matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);

    printf("Enter the source node in the graph:\n");
    scanf("%d",&source);

    printf("The nodes reachable from %d:",source);
    dfs(source);


}