#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

struct poly{
    int cf,px,py,pz;
    struct poly *link;
};
typedef  struct poly *NODE;

void read(NODE head);
void display(NODE head);
void eval();
void polysum();
void main(){
    int choice;
    while(1){
        printf("\n1:Polinomial Evaluation \n2:Polysum\n3:Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:eval();
        break;
        case 2:polysum();
        break;
        case 3:
        exit(0);
        }
    }
}

void read(NODE head){
    NODE temp,cur;
    int n,i;
    printf("\nEnter the number of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        temp=(NODE)malloc(sizeof(struct poly));
        printf("\nEnter cf,px,py,pz:\n");
        scanf("%d %d %d %d",&temp->cf,&temp->px,&temp->py,&temp->pz);
        temp->link=head;
        cur=head->link;
        while(cur->link!=head)
            cur=cur->link;
        cur->link=temp;
    }
}
void display(NODE head){
    NODE temp;
    if(head->link==head)
    {
        printf("Polinomial does not exist.\n");
        exit(0);
    }
    temp=head->link;
    while (temp!=head)
    {
        if(temp->cf<0)
        printf("%d",temp->cf);
        else
        printf("+%d",temp->cf);
        printf("x^%dy^%dz^%d",temp->px,temp->py,temp->pz);
        temp=temp->link;
    }
    printf("\n");
}
void eval(){
    NODE head,temp;
    int x,y,z,sum=0;
    head=(NODE)malloc(sizeof(struct poly));
    head->link=head;
    printf("Enter the Polynomial to evaluate:\n");
    read(head);
    printf("Polynomial:\n");
    display(head);
    printf("Enter the values of x,y,z:\n");
    scanf("%d %d %d",&x,&y,&z);
    temp=head->link;
    while (temp!=head)
    {
        sum+=(temp->cf)*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz);
        temp=temp->link;
    }
    printf("Sum = %d",sum);
}

void polysum(){
    NODE temp,cur,prev,head1,head2,cur1,cur2;
    int px,py,pz;
    head1=(NODE)malloc(sizeof(struct poly));
    head2=(NODE)malloc(sizeof(struct poly));
    head1->link=head1;
    head2->link=head2;
    printf("Enter the First Polynomial:");
    read(head1);
    printf("Enter the Second Polynomial:");
    read(head2);
    printf("Polynomial 1 is:");
    display(head1);
    printf("Polynomial 2 is:");
    display(head2);
    cur1=head1->link;
    while (cur1!=head1)
    {
        prev=head2;
        cur2=head2->link;
        while(cur2!=head2)
        {
            if(cur1->px==cur2->px && cur1->py==cur2->py && cur1->pz==cur2->pz){
                cur1->cf+=cur2->cf;
                prev->link=cur2->link;
                free(cur2);
                break;
            }
            prev=cur2;
            cur2=cur2->link;
        }
        prev=cur1;
        cur1=cur1->link;
    }
    prev->link=head2->link;
    head2->link=head1->link;
    printf("Resultant Polynomial is :");
    display(head2);
    
}