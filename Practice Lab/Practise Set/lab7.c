#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[10],usn[10],branc[10],sem[10],ph[10];
    struct student *link;
};

typedef struct student *NODE;

void main(){
    NODE temp,first=NULL,prev,cur;
    int choice,c=0;
    printf("The Singly Linked List Operations Are:\n");
    while(1){
        printf("\n1:insert front\n2:insert rear\n3:delete front\n4:delete rear\n5:display\n6:exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            temp=(NODE)malloc(sizeof(struct student));
            printf("enter the Name,Usn,Branch,Sem and Phone Number:\n");
            scanf("%s%s%s%s%s",temp->name,temp->usn,temp->branc,temp->sem,temp->ph);
            temp->link=first;
            first=temp;
            break;
            case 2:
            temp=(NODE)malloc(sizeof(struct student));
            printf("enter the Name,Usn,Branch,Sem and Phone Number:\n");
            scanf("%s%s%s%s%s",temp->name,temp->usn,temp->branc,temp->sem,temp->ph);
            temp->link=NULL;
            if(first==NULL){
                first=temp;
                break;
            }
            cur=first;
            while(cur->link!=NULL)
                cur=cur->link;
            cur->link=temp;
            break;
            case 3:
            if(first==NULL){
                printf("List is Empty.");
                break;
            }
            temp=first;
            first=first->link;
            free(temp);
            break;
            case 4:
            if(first==NULL){
                printf("List is Empty.");
                break;
            }
            if(first->link==NULL){
                printf("First Node in the list is deleted.");
                first=NULL;
                break;
            }
            cur=first;
            prev=NULL;
            while (cur->link!=NULL)
            {
                prev=cur;
                cur=cur->link;
            }
            prev->link=NULL;
            free(cur);
            break;
        case 5:
        c=0;//VIMP
        if(first==NULL){
                printf("List is Empty.");
                break;
            }
        printf("Name\t\t\tUSN\t\t\tBranch\t\t\tSem\t\t\tPhone Number:\n");
        temp=first;
        while(temp!=NULL){
            printf("%-20s%-20s%-20s%-20s%-20s\n",temp->name,temp->usn,temp->branc,temp->sem,temp->ph);
            temp=temp->link;
            c++;
        }
        printf("The number of Students In the List IS :%d\n",c);
        printf("\n");
        break;
        case 6:exit(0);
        }
    }

}