#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Day{
    char name[20];
    int date;
    char activity[20];
};

void read(struct Day calendar[],int n);
void display(struct Day calendar[],int n);

void main(){
    int n=7;
    struct Day calendar[n];
    read(calendar,n);
    display(calendar,n);
}
void read(struct Day calendar[],int n){
    printf("---Weekly Report---\n");
    for(int i=0;i<n;i++){
        printf("Enter the name of the day %d:\n",i+1);
        scanf("%s",calendar[i].name);
        printf("Enter the Date of %s:\n",calendar[i].name);
        scanf("%d",&calendar[i].date);
        printf("Enter the Activity of %s:\n\n",calendar[i].name);
        scanf("%s",calendar[i].activity);
    }
}


void display(struct Day calendar[],int n){
    for(int i=0;i<n;i++){
        printf("Day:%s\n",calendar[i].name);
        printf("Date:%d\n",calendar[i].date);
        printf("Activity:%s\n",calendar[i].activity);
    }
}

