#include<stdio.h>
int a[10][10],i,j,k,n;
void main(){
    printf("Enter the Number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    a[i][j]=a[i][j] || a[i][k] && a[k][j];
    printf("The Transitive closure is :\n");
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
}
