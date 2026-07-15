    // Quick Sort

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void Quick_Sort(int[], int, int);
    int Partition(int[], int, int);
    void print_Array(int arr[], int n);
    int arr[15000];
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
        Quick_Sort(arr, 0, n-1);
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

    void Quick_Sort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int s = Partition(arr,low,high);
            Quick_Sort(arr, low, s-1);
            Quick_Sort(arr, s + 1, high);
        }
    }
    int swap(int *a,int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    int Partition(int arr[], int l,int r)
    {
        int i, j,pivot;
        i = l;
        j=r;
        pivot=arr[i];
        while(i<j){
            while(i<r && arr[i]<=pivot)
            i++;
            while(j>l && arr[j]>pivot)
            j--;
            if(i<j){
                swap(&arr[i],&arr[j]);
            }
        }
        swap(&arr[j],&arr[l]);
        return j;

    }