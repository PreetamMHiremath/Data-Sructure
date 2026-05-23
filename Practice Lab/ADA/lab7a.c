#include<stdio.h>
int min(int ,int);
int i,j,k,c[10][10];

void main(){
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&c[i][j]);
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    c[i][j]=min(c[i][j],(c[i][k]+c[k][j]));
    printf("The all pair of shortest path is :\n");
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
    printf("%d\t",c[i][j]);
}
printf("\n");
}
}

int min(int x,int y){
    return x<y?x:y;
}