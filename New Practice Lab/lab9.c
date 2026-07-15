//Selection sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_Array(int [],int);

void selectionSort(int [],int);

void main(){
    int arr[15000],n,i;
    double total_time;
    clock_t start,end;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    arr[i]=rand()%n+1;
    printf("The Sorted Array is :\n");
    print_Array(arr,n);

    start=clock();
    selectionSort(arr,n);
    end=clock();
    total_time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted Array is:\n");
    print_Array(arr,n);
    printf("The total time to sort the array is :%f\n",total_time);
}

void print_Array(int arr[],int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
}

void selectionSort(int arr[],int n){
    int min,i,j,temp;
    for(i=0;i<n-2;i++){
        min=i;
    for(j=i+1;j<n-1;j++){
        if(arr[j]<arr[min])
        min=j;
    }
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
}
}