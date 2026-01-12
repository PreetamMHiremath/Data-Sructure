#include<stdio.h>
#include<stdlib.h>
#define max 20
void push();
void pop();
void palindrome();
void display();

int choice,s[max],top=-1,temp=0,i=0,elem=0;


void main(){
    printf("The Stack Operations are:");
    while (1)
    {
        printf("\n1:Push\n2:Pop\n3:Palindrome\n4:Display\n5:exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:palindrome();break;
            case 4:display();break;
            case 5:exit(0);
        }
    }
    
}

void push(){
    if(top==max-1)
        printf("Stack is OverFlow.");   
    else{
        printf("Enter the element to be insert:\n");
        scanf("%d",&elem);
        s[++top]=elem;
    }
}


void pop(){
    if(top==-1)
        printf("Stack is Underflow.");
    else{
        printf("Last element in the list is deleted.");
        top--;   
    }
}

void palindrome(){
    printf("Enter the number to find the Palinderome:\n");
    scanf("%d",&elem);
    top=-1;
    temp=elem;
    while (temp)
    {
        s[++top]=temp%10;
        temp=temp/10;
    }
    temp=elem;
    while (temp)
    {
        if(s[top--]!=temp%10){
            printf("It is not a Palindrome.");
            return ;
        }
        temp/=10;
    }
    printf("It is a Palindrome\n");
}

void display(){
    if(top==-1){
        printf("Stack is Empty.");
        return;
    }
    printf("The Stack elements are:\n");
    for(i=0;i<=top;i++){
        printf("%d\n",s[i]);
    }
}