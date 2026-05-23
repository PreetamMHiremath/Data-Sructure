#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int info;
    struct BST *llink, *rlink;
};
typedef struct BST *NODE;

/* ---------------- INORDER TRAVERSAL ---------------- */
void inorder(NODE root)
{
    if(root == NULL)
        return;

    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

/* ---------------- PREORDER TRAVERSAL ---------------- */
void preorder(NODE root)
{
    if(root == NULL)
        return;

    // ❌ In your code printf and return were on same line (confusing)
    // return; printf("%d,",root->info);

    // ✅ Proper formatting
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

/* ---------------- POSTORDER TRAVERSAL ---------------- */
void postorder(NODE root)
{
    if(root == NULL)
        return;

    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

int main()   // ❌ void main() → non-standard
{
    NODE root = NULL, temp, cur, prev;
    int choice, item;

    while(1)
    {
        printf("\n\nOperations of Binary Search Tree\n");
        printf("1. Create\n");
        printf("2. Traverse\n");
        printf("3. Search key element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            /* ---------------- CREATE BST NODE ---------------- */
            case 1:
                temp = (NODE)malloc(sizeof(struct BST));  // ✅ correct malloc
                if(temp == NULL)
                {
                    printf("Memory allocation failed\n");
                    break;
                }

                printf("Enter an element: ");
                scanf("%d", &item);

                temp->info = item;
                temp->llink = temp->rlink = NULL;

                if(root == NULL)
                {
                    root = temp;
                    break;
                }

                cur = root;
                prev = NULL;

                while(cur != NULL)
                {
                    prev = cur;

                    if(item == cur->info)
                    {
                        printf("Duplicate items are not allowed\n");
                        free(temp);
                        temp = NULL;
                        break;
                    }
                    else if(item < cur->info)
                        cur = cur->llink;
                    else
                        cur = cur->rlink;
                }

                // ❌ temp may be freed already
                // ✅ Check before linking
                if(temp != NULL)
                {
                    if(item < prev->info)
                        prev->llink = temp;
                    else
                        prev->rlink = temp;
                }
                break;

            /* ---------------- TRAVERSALS ---------------- */
            case 2:
                if(root == NULL)
                {
                    printf("Tree is empty\n");
                    break;
                }

                printf("\nInorder Traversal : ");
                inorder(root);

                printf("\nPreorder Traversal : ");
                preorder(root);

                printf("\nPostorder Traversal : ");
                postorder(root);
                printf("\n");
                break;

            /* ---------------- SEARCH ---------------- */
            case 3:
                if(root == NULL)
                {
                    printf("Tree is empty\n");
                    break;
                }

                printf("Enter key element: ");
                scanf("%d", &item);

                cur = root;
                while(cur != NULL)
                {
                    if(item == cur->info)
                    {
                        printf("Element is found\n");
                        break;
                    }
                    else if(item < cur->info)
                        cur = cur->llink;
                    else
                        cur = cur->rlink;
                }

                if(cur == NULL)
                    printf("Element is not found\n");
                break;

            /* ---------------- EXIT ---------------- */
            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
