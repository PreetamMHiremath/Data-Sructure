#include<stdio.h>
int i,j,k,n,c[10][10];

void main(){
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjency matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&c[i][j]);
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    c[i][j]=c[i][j] || (c[i][k] && c[k][j]);
    printf("The transitive closure is :\n");
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
    printf("%d\t",c[i][j]);
    }
    printf("\n");
    }
}