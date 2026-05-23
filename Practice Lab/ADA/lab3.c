#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void QuickSort(int [], int, int);
int partition(int [], int, int);
void print_array(int [], int);
void swap(int *, int *);

void main()
{
    int i, n, arr[15000];
    clock_t start, end;
    double time_taken;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("Generating random elements:\n");

    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }

    printf("The unsorted array is:\n");
    print_array(arr, n);

    start = clock();

    QuickSort(arr, 0, n - 1);

    end = clock();

    printf("The sorted array is:\n");
    print_array(arr, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("The total time taken to sort the array using Quick Sort: %f seconds\n", time_taken);
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

void QuickSort(int arr[], int l, int r)
{
    int s;

    if(l < r)
    {
        s = partition(arr, l, r);

        QuickSort(arr, l, s - 1);
        QuickSort(arr, s + 1, r);
    }
}

int partition(int arr[], int l, int r)
{
    int i, j, pivot;

    i = l;
    j = r;
    pivot = arr[l];

    while(i < j)
    {
        while(i < r && arr[i] <= pivot)
        {
            i++;
        }

        while(j > l && arr[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[l], &arr[j]);

    return j;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}