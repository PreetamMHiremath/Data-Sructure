#include<stdio.h> 
#define Hash_Size 10 

int main() 
{ 
    FILE *fp; 
    int i,key,hv,index,HT[Hash_Size];     

    for(i=0;i<Hash_Size;i++) 
        HT[i]=-1; 

    fp = fopen("td.txt","r"); 
    if(fp == NULL){
        printf("File not found");
        return 1;
    }

    while(fscanf(fp,"%d",&key) != EOF) 
    { 
        hv = key % Hash_Size; 

        if(HT[hv] == -1) 
            HT[hv] = key; 
        else 
        { 
            printf("\nCollision for key %d\n", key); 

            for(i=1;i<Hash_Size;i++) 
            { 
                index = (hv + i) % Hash_Size; 

                if(HT[index] == -1)      
                { 
                    HT[index] = key; 
                    printf("Collision solved using linear probing\n"); 
                    break; 
                } 
            } 
        } 
    } 

    printf("\nAddress\tKey\n"); 
    for(i=0;i<Hash_Size;i++) 
        printf("%d\t%d\n", i, HT[i]); 

    fclose(fp);
    return 0;
}
