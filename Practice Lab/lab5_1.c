#include<stdio.h>

void tower(int n,char s,char t,char d){
    if(n==0) return;
    tower(n-1,s,d,t);
    printf("Move Disc %d from %c to %c\n",n,s,d);
    tower(n-1,t,s,d);
}
void main(){
    int n;
    printf("Enter no of Discs:");
    scanf("%d",&n);
    tower(n,'A','B','C');
}