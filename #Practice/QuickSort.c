#include <stdio.h>
#include <time.h>

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int p, int r)
{
    int x = arr[p];
    int  i = p;
    for (int j = p; j <= r; j++)
    {
        if (arr[j] < x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[p]);
    return i;
}
void QuickSort(int arr[] , int p, int r)
{
    if (p < r)
    {
        int q =  partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q+1, r);
    }
}

int main()
{
    int n;
    printf ("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n], k;
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

    clock_t start, end;
    double total_t;
    
    start = clock();
    QuickSort(arr, 0, n-1);
    end = clock();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }


    total_t = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime required: %.10f\n", total_t);
    return 0;
}