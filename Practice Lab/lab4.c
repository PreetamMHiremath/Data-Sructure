#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int F(char ch){
    switch (ch)
    {
        case '+':
        case '-': return 2; break;
        case '*':
        case '/':
        case '%': return 4; break;
        case '^':
        case '$': return 5; break;
        case '(':return 0;
        case '#':return -1;
        default:return 8;
        }
}
int G(char ch){
    switch (ch)
    {
        case '+':
        case '-': return 1; break;
        case '*':
        case '/':
        case '%': return 3; break;
        case '^':
        case '$': return 6; break;
        case '(':return 9;
        case ')':return 0;
        default:return 7;
        }
}

void main(){
    char infix[20],postfix[20],s[20];
    int i=0,top=-1,j=0;
    printf("Enter the infix Statement:");
    scanf("%s",infix);
    s[++top]='#';
    for(i=0;i<strlen(infix);i++){
        while(F(s[top])>G(infix[i]))
        postfix[j++]=s[top--];
        if(F(s[top])!=G(infix[i]))
        s[++top]=infix[i];
        else
        top--;
    }
    while(s[top]!='#')
    postfix[j++]=s[top--];    
    postfix[j]='\0';
    printf("After converting infix to Postfix %s",postfix);
}