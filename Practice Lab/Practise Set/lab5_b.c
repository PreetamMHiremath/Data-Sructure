#include<stdio.h>
void tower(int n,char s,char t,char d);


void main(){
    int n;
    printf("Enter the Number of Discs:\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
}


void tower(int n,char s,char t,char d){
    if(n==0) return;// Important Condition
    tower(n-1,s,d,t);
    printf("Move Disc %d from %c to %c\n",n,s,d);
    tower(n-1,t,s,d);
}
