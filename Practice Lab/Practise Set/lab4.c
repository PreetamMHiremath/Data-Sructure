#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[10],postfix[10],s[10];
int top=-1,i=0,j=0;

int F(char ch){
    switch (ch)
    {
        case '+':
        case '-':
        return 2;

        case '*':
        case '/':
        case '%':
        return 4;

        case '^':
        case '$':
        return 5;

        case '(':
        return 0;

        case '#':
        return -1;

        default:
        return 8;
        
    }
}
int G(char ch){
    switch (ch)
    {
        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        case '%':
        return 3;

        case '^':
        case '$':
        return 6;

        case '(':
        return 9;

        case ')':
        return 0;

        default:
        return 7;
        
    }
}
void main(){
    printf("Enter the infix Expression:\n");
    scanf("%s",infix);
    s[++top]='#';
    for(i=0;i<strlen(infix);i++){
        while (F(s[top])>G(infix[i]))
            postfix[j++]=s[top--];
        if(F(s[top])!=G(infix[i])) //Check the parenthesis
            s[++top]=infix[i];
        else
        top--;
    }
    while(s[top]!='#')
        postfix[j++]=s[top--];
    postfix[j]='\0';
    printf("The Postfix Expression is :%s\n",postfix);

}