#include<stdio.h>
#include<stdlib.h>

struct Employee
{
    char name[10],ssn[10],dept[10],designation[10],sal[10],ph[10];
    struct Employee *llink,*rlink;
};
typedef struct Employee *NODE;

int main(){
    NODE temp,cur,first=NULL,prev;
    int choice,c=0;
    printf("The Doubly Linked List Are:\n");
    while(1){
        printf("\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Display\n6:Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            temp=(NODE)malloc(sizeof(struct Employee));
            printf("Enter Name,SSN,Dept,Desi,Sal,PhNO:\n");
            scanf("%s%s%s%s%s%s",temp->name,temp->ssn,temp->dept,temp->designation,temp->sal,temp->ph);
            temp->llink=temp->rlink=NULL;
            if(first==NULL){
                first=temp;
                break;
            }
            temp->rlink=first;
            first->llink=temp;
            first=temp;
            break;
        case 2:
            temp=(NODE)malloc(sizeof(struct Employee));
            printf("Enter Name,SSN,Dept,Desi,Sal,PhNO:\n");
            scanf("%s%s%s%s%s%s",temp->name,temp->ssn,temp->dept,temp->designation,temp->sal,temp->ph);
            temp->llink=temp->rlink=NULL;
            if(first==NULL){
                first=temp;
                break;
            }
            cur=first;
            while (cur->rlink!=NULL)
            {
               cur=cur->rlink;
            }
            cur->rlink=temp;
            temp->llink=cur;
            break;
        case 3:
            if(first==NULL){
                printf("List is Empty.");
                break;
            }
            temp=first;
            first=first->rlink;
            first->llink=NULL;
            free(temp);
            break;
        case 4:
            if(first==NULL){
                printf("List is Empty.");
                break;
            }
            if(first->rlink==NULL){
                printf("First Node in the list is Empty.");
                first=NULL;
                break;
            }
            cur=first;
            prev=NULL;
            while (cur->rlink!=NULL)
            {
                prev=cur;
                cur=cur->rlink;
            }
            prev->rlink=NULL;
            free(cur);
            break;
        case 5:
        c=0;
        if(first==NULL)
        {
                printf("List is Empty.");
                break;
        }
        printf("Name\t\tSSN\t\tDept\t\tDesi\t\tSal\t\tPhNO\n");
        temp=first;
        while (temp!=NULL)
        {
            printf("%-20s%-20s%-20s%-20s%-20s%-20s\n",temp->name,temp->ssn,temp->dept,temp->designation,temp->sal,temp->ph);
            temp=temp->rlink;
            c++;

        }
        printf("The List Conatining %d Employees.",c);
        break;
    case 6:
        exit(0);
        }
    }
return 0;
}