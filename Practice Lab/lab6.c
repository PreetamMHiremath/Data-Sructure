#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

char q[MAX],elem;
int r=-1,f=0,front=0,c=0,choice;

void insert();
void delete();
void display();

void main(){
    printf("Queue Operations are");
    while(1){
        printf("\n1:Insert\n2:Delete\n3:Display\n4:exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);
            switch (choice)
            {   
                case 1:insert();break;
                case 2:delete();break;
                case 3:display();break;
                case 4:exit(0);
            }

    }
}

void insert(){
    if(c==MAX){
        printf("Queue is Full");
    }
    else{
        printf("Enter the elements To Be Insert");
        scanf(" %c",&elem);
        r=(r+1)%MAX;
        q[r]=elem;
        c++;
    }
} 

void delete(){
    if(c==0){
        printf("Queue is empty");
    }
    else{
        printf("The elements is deleted ");
        f=(f+1)%MAX;
        c--;
    }
}

void display(){
    if(c==0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The queue elements are :");
        front=f;
        for(int i=0;i<c;i++){
            printf("%c",q[front]);
            front=(front+1)%MAX;
        }
    }
}
