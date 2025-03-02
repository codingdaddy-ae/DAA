#include <stdio.h>
#include <time.h>
void swap (int *a, int *b)
int partition(int arr[],int p, int r)
{
    int x = arr[p];
    
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]< arr[min])
            min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    printf("Enter the element to be searched: ");
    scanf("%d", &k);
    
    clock_t start, end;
    double total_t;

    sort(arr,n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    start = clock();
    binary(arr, 0, n, k);
    end = clock();

    total_t = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time required: %.10f\n", total_t);
    return 0;
}