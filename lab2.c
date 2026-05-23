#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void print_array(int arr[], int n);

int n, arr[15000], b[15000];

void main()
{
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The unsorted array is:\n");
    print_array(arr, n);

    start = clock();

    mergeSort(arr, 0, n - 1);

    end = clock();

    printf("The sorted array is:\n");
    print_array(arr, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("The total time taken to sort the array using Merge Sort: %f seconds\n", time_taken);
}

void print_array(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    while(i <= m)
    {
        b[k++] = arr[i++];
    }

    while(j <= r)
    {
        b[k++] = arr[j++];
    }

    for(i = l; i <= r; i++)
    {
        arr[i] = b[i];
    }
}