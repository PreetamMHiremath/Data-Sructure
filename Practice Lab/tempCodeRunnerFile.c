#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[10],usn[10],bran[10],sem[10],pho[10];
    struct student *link;
};
typedef struct student *NODE;
void main(){
    int choice,c=0;
    NODE first=NULL,cur,prev,temp;
    printf("The Singly Linked List.");
    while (1)
    {
        printf("\n1:Insert Front\n2:Insert rear\n3:Delete Front\n4:Delete rear\n5:Display\n6:exit\n");
        printf("Enter Your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:temp=(NODE)malloc(sizeof(struct student));            
        printf("Enter name, usn, bran, sem, pho\n");
        scanf("%s%s%s%s%s",temp->name,temp->usn,temp->bran,temp->sem,temp->pho);
        temp->link=first;
        first=temp;
        break;
        case 2:temp=(NODE)malloc(sizeof(struct student));            
        printf("Enter name, usn, bran, sem, pho\n");
        scanf("%s%s%s%s%s",temp->name,temp->usn,temp->bran,temp->sem,temp->pho);
        temp->link=NULL;
        if(first==NULL){
            first=temp;
            break;
        }
        cur=first;
        while(cur->link!=NULL){
            cur=cur->link;
        }
        cur->link=temp;
        break;
        case 3:
        if(first==NULL){
            printf("List is Empty");
            break;
        }
        temp=first;
        first=first->link;
        free(temp);
        break;
        case 4:
        if(first==NULL){
            printf("List is Empty");
            break;
        }
        if(first->link==NULL){
            first=NULL;
            break;
        }
        prev=NULL;
        cur=first;
        while(cur->link!=NULL){
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        free(cur);
        break;
        case 5:
        if(first==NULL){
            printf("List is Empty");
            break;
        }
        c=0;
        printf("The Singly Linked lists Are");
        temp=first;
        printf("Name:\tUSN\tSEM\tBrach\tPhone\n");
        while(temp!=NULL){
            printf("%-20s%-20s%-20s%-20s%-20s",temp->name,temp->usn,temp->sem,temp->bran,temp->pho);
            temp=temp->link;
            c++;
        }
        printf("The Total numbers of Students are the Singly linked list are %d",c);
        break;
        case 6:exit(0);
    }

    
    }
       
}