#include<stdio.h>
#include<stdlib.h>

char str[20],pat[20],rep[20],res[20];
int i=0,j=0,k=0,l=0,ls=0,lp=0,lr=0,exist=0;//Intialize all with 0

void read();
void match();


void main(){
    read();
    match();
}

void read(){
    printf("Enter the main string:\n");
    scanf("%s",str);
    printf("Enter the Pattern string:\n");
    scanf("%s",pat);
    printf("Enter the Replace string:\n");
    scanf("%s",rep);
    printf("\n");
}

void match(){
    while(str[ls]!='\0')
        ls++;
    while(pat[lp]!='\0')
        lp++;
    while(rep[lr]!='\0')// very imp for single quotes
        lr++;

    while(i<=ls-lp){ //Here the main Important is <= 
        j=0;
        while(j<lp && pat[j]==str[i+j])
            j++;
        if(j==lp){
            exist=1;
            while(l<i)
                res[k++]=str[l++];
            l=0;
            while(l<lr)
                res[k++]=rep[l++];
            i=i+lp;
            l=i;
        }   
        else
        i++;
    }
    if(exist==0){
        printf("Pattern Does not Match.");
        exit(0);
    }
    while(l<ls)
        res[k++]=str[l++];
    res[k]='\0';
    printf("After Replacing the string is :%s",res);
}