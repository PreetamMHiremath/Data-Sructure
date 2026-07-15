#include<stdio.h>
int arr[10][10],indegree[10],source,n;
int findSource();
void sourceRemoval();
void main(){
    int i,j;
    printf("Enter the size of the adjancey matrix:\n");
    scanf("%d",&n);
    printf("Enter the adjancey matrix\n");
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
    scanf("%d",&arr[i][j]);
    if(arr[i][j]==1)
    indegree[j]++;
    }
    }
    source=findSource();
    if(source!=-1){
        printf("Topological sorting using source removal method:\n");
        sourceRemoval();
    }
    else
    printf("Topological sorting is not possible.");

}

int findSource(){
    int i;
    for ( i = 1; i <= n; i++)
        if(indegree[i]==0)
        return i;
    return -1;
}

void sourceRemoval(){
    int j;
    while (source!=-1)
    {
        printf("%d",source);
        indegree[source]=-1;
        for (j=1;j<=n;j++)
        if(arr[source][j]==1)
        indegree[j]--;
        source=findSource();
    }
    
}
