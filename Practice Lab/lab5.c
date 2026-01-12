#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void main(){
    int top=-1,op1,op2,i=0,result,s[20];
    char postfix[20];
    printf("Enter postfix Expressin:");
    scanf("%s",postfix);
    for (i=0;i<strlen(postfix);i++){
        if(isdigit(postfix[i]))
        s[++top]=postfix[i]-'0';
        else{
            op2=s[top--];
            op1=s[top--];
            switch (postfix[i])
            {
                case '+':result=op1+op2;break;
                case '-':result=op1-op2;break;
                case '*':result=op1*op2;break;
                case '/':result=op1/op2;break;
                case '%':result=op1%op2;break;
                case '^':result=pow(op1,op2);break;
            }
            s[++top]=result;
        }

    }
    printf("Result:%d231*+9-",result);
}

