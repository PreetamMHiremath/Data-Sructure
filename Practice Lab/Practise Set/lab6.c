#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5

char elem,q[max];
int c=0,r=-1,f=0,front,choice;

void insert();
void delete();
void display();

void main(){
    printf("Queue Operations are :\n");
    while(1){
        printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
        printf("Enter Your choice:\n");
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
    if(c==max-1){
        printf("Queue is Full.");
    }
    else{
        printf("Enter the element to be insert:\n");
        scanf(" %c",&elem);
        r=(r+1)%max;
        q[r]=elem;
        c++;//Important don't forget
    }
}
void delete(){
    if(c==0){
        printf("Queue is Empty.");
    }
    else{
        f=(f+1)%max;
        printf("Element is Deleted.");
        c--;
    }
}

void display(){
    printf("The Queue elements Are:\n");
    front=f;
    for(int i=0;i<=c;i++)
    {   
        printf("%c\n",q[front]);// Important
        front=(front+1)%max;
    }
    
}