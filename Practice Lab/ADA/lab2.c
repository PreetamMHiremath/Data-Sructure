#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void MergeSort(int[], int, int);
void Merge(int[], int, int, int);
void Print_Array(int[], int);
int arr[150000], b[150000], n ;

int main()
{
int i;
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
MergeSort(arr, 0, n-1);
end = clock();
printf("The Sorted Array is:\n");
Print_Array(arr, n);
time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("time taken to sort %d numbers using Merge sort = %f\n", n,
time_taken );
}
void Print_Array(int a[], int n)
{
int i;
for(i = 0; i < n; i++)
printf("%d\t", a[i]);
printf("\n\n");
}

void MergeSort(int a[], int low, int high)
{
int mid;
if (low < high)
{
mid = (int) ((low + high) / 2);
MergeSort(a, low, mid);
MergeSort(a, mid+1, high);
Merge(a, low, mid, high);
}
}
void Merge(int a[], int l, int m, int r)
{
int i, j, k;
i = l;
j = m + 1;
k = l;
while (i<=m && j<=r)
{
if(a[i] <= a[j])
b[k++] = a[i++];
else
b[k++] = a[j++];
}
while(i <=m)
b[k++] = a[i++];
while(j<=r)
b[k++] = a[j++];

for(i = l; i<k; i++)
a[i] = b[i];
}