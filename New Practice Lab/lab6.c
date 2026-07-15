#include<stdio.h>
int a[10][10],i,n,w,wt[20],val[20],max_profit;
int knapsack(int,int [],int [],int);
void main(){
    printf("Enter the Number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the weight of profit of items:\n");
    for(i=1;i<=n;i++)
    scanf("%d%d",&wt[i],&val[i]);
    printf("Enter the maximum capacity of bag:\n");
    scanf("%d",&w);
    max_profit=knapsack(w,wt,val,n);
    printf("The maximum profit=:%d",max_profit);
    }

int max(int a,int b){
    return a>b?a:b;
}
int knapsack(int w,int wt[],int val[],int n){
    if(w==0 || n==0){
        return 0;
    }
    else if(wt[n]>w){
        return knapsack(w,wt,val,n-1);
    }
    else
        return max(val[n]+knapsack(w-wt[n],wt,val,n-1),knapsack(w,wt,val,n-1));
    }
