#include<stdio.h> 
 int a[10][10],n,s[10]; 
 
void dfs(int  u) 
{ 
  int v,i; 
  s[u]=1; 
  printf("%d",u); 
  for(v=0;v<n;v++) 
       { 
         if(a[u][v]==1 && s[v]==0) 
         dfs(v); 
        } 
} 
 
 void main( ) 
   { 
  int i,j,source; 
  printf("Enter no of nodes in the graph \n"); 
  scanf("%d",&n); 
   
  printf("Enter adjacency matrix \n"); 
  for(i=0;i<n;i++) 
  for(j=0;j<n;j++) 
  scanf("%d",&a[i][j]); 
   
  printf("Enter source node in the graph \n"); 
  scanf("%d",&source); 
 
  printf("\n The nodes reachable from %d:",source); 
  dfs(source); 
  printf("\n"); 
   }