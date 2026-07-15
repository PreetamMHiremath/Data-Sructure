// Merge sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int[], int, int);
void merge(int[], int, int, int);
void selectionSort(int[], int);
void print_Array(int arr[], int n);
int arr[15000], b[150000];
void main()
{
    int n, i;
    double total_time;
    clock_t start, end;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        arr[i] = rand() % n + 1;
    printf("The Unorted Array is :\n");
    print_Array(arr, n);

    start = clock();
    merge_sort(arr, 0, n-1);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The sorted Array is:\n");
    print_Array(arr, n);
    printf("The total time to sort the array is :%f\n", total_time);
}

void print_Array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= r)
        b[k++] = arr[j++];
    for (i = l; i < k; i++)
        arr[i] = b[i];
}