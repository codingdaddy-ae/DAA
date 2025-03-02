#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];                      //pivot choosing
    int i = p - 1;                      // indexing
    for (int j = p; j < r; j++)
    {
        if (arr[j] < x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void QuickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);


    clock_t start, end;
    double total_t;
    int arr[n];
   
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
   
    start = clock();
    QuickSort(arr, 0, n - 1);
    end = clock();
   
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
   
    total_t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime required = %f seconds\n", total_t);
   
    return 0;
}
