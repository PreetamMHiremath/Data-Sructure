#include<stdio.h>

#include<stdlib.h>

struct BST{
    int info;
    struct BST *rlink,*llink;
};
typedef struct BST *NODE;
void preorder(NODE root){
    if(root==0) return;
    printf("%d",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root){
    if(root==0) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d",root->info);
}
void inorder(NODE root){
    if(root==0) return;
    inorder(root->llink);
    printf("%d",root->info);
    inorder(root->rlink);
}

int main(){
    NODE cur,prev,root=NULL,temp;
    int choice,item;
    while(1){
        printf("\n1:create\n2:traverse\n3:nsearch key element\n4exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        temp = (NODE)malloc(sizeof(struct BST));
        printf("Enter the element:");
        scanf("%d",&item);
        temp->info=item;
        temp->llink=temp->rlink=NULL;
        if(root==NULL){
            root=temp;
            break;
        }
        cur=root;
        prev=NULL;
        if(item==cur->info){
            printf("Dublications are not allowed");
            break;
        }
        while(cur!=NULL){
            prev=cur;
            if(item<cur->info)
            cur=cur->llink;
            else
            cur=cur->rlink;
        }
        if(item<prev->info)
        prev->llink=temp;
        else
        prev->rlink=temp;
        break;
        case 2:
        printf("content of the tree\n");
        printf("Preorder\n");
        preorder(root);

        printf("Postorder\n");
        postorder(root);

        printf("Inorder\n");
        inorder(root);
        break;
        case 3:
        if(root==NULL){
            printf("It is empty");
            break;
        }
        printf("Enter the searching element:");
        scanf("%d",&item);
        cur=root;
        while (cur!=NULL)
        {
            if(item==cur->info){
                printf("Element is found.");
                break;
            }
            if(item<cur->info)
            cur=cur->llink;
            else
            cur=cur->rlink;
        }
        if(cur==NULL){
            printf("Element is not found.");
            break;
        }
        case 4:
        exit(0);
        }
    }
}
