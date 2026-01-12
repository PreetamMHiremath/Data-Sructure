#include<stdio.h>
#include<stdlib.h>

#define Hash_size 10

int main(){
    FILE *fp;
    int hv,HT[Hash_size],key,index,i;
    for(i=0;i<Hash_size;i++)
    HT[i]=-1;
    fp=fopen("data.txt","r");
    if(fp==NULL){
        printf("File Opening Failed.\n");
        return 0;
    }
    while (!feof(fp))
    {
        fscanf(fp,"%d",&key);
        hv=key%Hash_size;
        if(HT[hv]==-1)
        HT[hv]=key;
        else{
            printf("Collision occor for the Key is %d\n",key);
            for ( i = 0; i < Hash_size; i++)
            {
                index=(hv+i)%Hash_size;
                if(HT[index]==-1){
                    printf("collidion will be solved By using Linear Probing.\n");
                    HT[index]=key;
                    break;
                }
            }
            
        }
    }
    printf("Address \t\t Key:\n");
    for ( i = 0; i < Hash_size; i++)
    {
        printf("%d\t\t%d\n",i,HT[i]);
    }
    
    
}