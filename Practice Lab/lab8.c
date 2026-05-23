#include<stdio.h>
#include<stdlib.h>
struct Employee{
    char name[25],ssn[25],dep[25],des[25],sal[25],pho[25];
    struct Employee *llink,*rlink;
};
typedef struct Employee *NODE ;

void main(){
    NODE first=NULL,cur,prev,temp;
    int choice,c;
    printf("The Singly linked list operations are:");
    while(1){
        printf("\n1:insert front\n2:insert rear\n3:delete front\n4:delete rear\n5:display\n6:exit");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            temp=(NODE)malloc(sizeof(struct Employee));
            printf("Enter Name,SSN,Salary,Department,Designation,phone\n");
            scanf("%s%s%s%s%s%s",temp->name,temp->ssn,temp->sal,temp->dep,temp->des,temp->pho);
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
        printf("Enter Name,SSN,Salary,Department,Designation,phone\n");
        scanf("%s%s%s%s%s%s",temp->name,temp->ssn,temp->sal,temp->dep,temp->des,temp->pho);
        temp->llink=temp->rlink=NULL;
        if(first==NULL){
            first=temp;
            break;
        }
        cur=first;
        while(cur->rlink!=NULL)
        cur=cur->rlink;
        cur->rlink=temp;
        temp->llink=cur;
        break;
        case 3:
        if(first==NULL){
            printf("DLL is empty");
            break;
        }
        printf("First Element in the Lst is deleted.");
        temp=first;
        first=first->rlink;
        first->llink=NULL;
        free(temp);
        break;
        case 4:
        if(first==NULL){
            printf("DLL is empty");
            break;
        }
        if(first->rlink==NULL){
            first=NULL;
            break;
        }
        prev=NULL;
        cur=first;
        while (cur->rlink!=NULL)
        {
            prev=cur;
            cur=cur->rlink;
        }
        prev->rlink=NULL;
        break;
    case 5:
    printf("The employee Details stored in the doubly linked list are:\n");
    printf("Name:\t\tSSN\t\tDept\t\tDes\t\tSal\t\tPho:");
    temp=first;
    while(temp!=NULL){
    printf("%-20s%-20s %-20s %-20s %-20s %-20s",temp->name,temp->ssn,temp->sal,temp->dep,temp->des,temp->pho);
    printf("\n");
    temp=temp->rlink;
    c++;

}
    printf("Total Numbers of the Employees in Our Compnay is");
    break;
    case 6:exit(0);
    }
}
}
