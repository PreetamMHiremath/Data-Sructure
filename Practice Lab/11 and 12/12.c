#include<stdio.h> 
#define  Hash_Size 10 
int HT[Hash_Size]; 
main( ) 
{ 
    FILE *fp; 
    int i,key,hv,index; 
    char name[20]; 
    for(i=0;i< Hash_Size;i++) 
    HT[i]=-1; 
    fp=fopen("1.txt","r"); 
    while(!feof(fp)) 
       { 
            fscanf(fp," %d %s ",&key,name); 
            hv=key% Hash_Size; 
             if(HT[hv]==-1) 
              HT[hv]=key; 
          else 
                { 
printf("\ncollision for key %d:\n",key); 
                   for(i=0;i< Hash_Size;i++) 
                       { 
                          index=(hv+i)% Hash_Size; 
                           if(HT[index]==-1) 
                              { 
                        HT[index]=key; 
                        printf("\ncollision solved using linear probing\n"); 
                        break;    
                             } 
                       }    
         } 
    } 
    if(i== Hash_Size) 
    printf("hash table is full"); 
    printf("-------------\n"); 
    printf("hash table\n"); 
    printf("---------\n"); 
    printf("adress\tkey\n"); 
    for(i=0; i< Hash_Size; i++) 
    printf("%d\t %d\n",i,HT[i]); 
} 