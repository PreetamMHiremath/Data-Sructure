#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void QuickSort(int[], int, int );
void Print_Array(int[], int );
int Partition(int[], int, int);
void Swap (int*, int*);
int main()
{
int arr[150000], n, i;
clock_t start, end;
double time_taken;
printf("enter the size of the array \n");
scanf("%d", &n);
for(i=0; i<n; i++) {
arr[i] = rand() % n + 1;
}
printf("The Unsorted Array is:\n");
Print_Array(arr, n);
start = clock();
QuickSort(arr, 0, n-1);
end = clock();
printf("The Sorted Array is:\n");
Print_Array(arr, n);
time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("time taken to sort using Quick sort = %f\n", time_taken );
}
void Print_Array(int a[], int n)

{
int i;
for( i = 0; i < n; i++)
printf("%d\t", a[i]);
printf("\n\n");
}
void Swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b =temp;
}
void QuickSort(int a[], int l, int r)
{
int s;
if (l<r)
{
s = Partition(a, l, r);
QuickSort(a, l, s-1);
QuickSort(a, s+1, r);
}
}
int Partition(int a[], int l, int r)
{
int pivot, i, j;
pivot = a[l];
i = l;
j = r ;

while(i < j){
while( i < r && a[i] <= pivot)
i++;
while( j > l && a[j] > pivot)
j--;
if(i < j)
Swap(&a[i], &a[j]);
}
Swap(&a[l], &a[j]);
return j;
}