#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int main(){
    char postfix[20];
    int top=-1,s[10],op1,op2,result,i;
    printf("Enter the postfix Expression:\n");
    scanf("%s",postfix);
    for(i=0;i<strlen(postfix);i++){
        if(isdigit(postfix[i]))
            s[++top]=postfix[i]-'0';
            else{
                op2=s[top--];
                op1=s[top--];
                switch (postfix[i])
                {
                case '+':result=op1+op2;
                break;
                case '-':result=op1-op2;
                break;
                case '*':result=op1*op2;
                break;
                case '/':result=op1/op2;
                break;
                case '%':result=op1%op2;
                break;
                case '^':result=pow(op1,op2);
                break;
                }
                s[++top]=result;
        }
    }
    printf("Result:%d\n",result);
}