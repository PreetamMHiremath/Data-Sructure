#include<stdio.h>
int knapsack(int,int[],int[],int);
int max(int,int);
void main(){
    int w,wt[10],val[10],n,max_profit,i;
    printf("Enter the no of items:\n");
    scanf("%d",&n);
    printf("Enter the weight of profit of itmes:\n");
    for(i=1;i<=n;i++)
        scanf("%d%d",&wt[i],&val[i]);
    printf("Enter the capacity of bag:\n");
    scanf("%d",&w);
    max_profit=knapsack(w,wt,val,n);
    printf("The maximum capacity is :%d",max_profit);
}

int knapsack(int w,int wt[],int val[],int n){
    if(w==0 || n==0)
        return 0;
    else if(wt[n]>w)
        return knapsack(w,wt,val,n-1);
    else
        return max((val[n]+knapsack(w-wt[n],wt,val,n-1)),knapsack(w,wt,val,n-1));
}
int max(int a,int b){
    return a>b?a:b;
}