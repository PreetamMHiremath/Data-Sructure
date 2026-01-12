#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Day{
    char *name;
    int date;
    char *activity;
};

int main(){
    int i,n=7;
    struct Day *calendar=(struct Day*)malloc(n*sizeof(struct Day));
    if(calendar==NULL){
        printf("Dynamic Memory allocation failed.");
        return 0;
    }
    for(i=0;i<n;i++){
        calendar[i].name=(char *)malloc(20*sizeof(char));
        calendar[i].activity=(char *)malloc(20*sizeof(char));
    }
    strcpy(calendar[0].name,"Monday");
    calendar[0].date=1;
    strcpy(calendar[0].activity,"Playing Game");
    printf("\nDay:%s:\nDate:%d\nActivity:%s",calendar[0].name,calendar[0].date,calendar[0].activity);
    for(i=0;i<n;i++){
    free(calendar[i].name);
    free(calendar[i].activity);
    }
    free(calendar);
    return 0;
}