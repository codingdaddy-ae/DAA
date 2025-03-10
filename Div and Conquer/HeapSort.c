#include <stdio.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < min)
        min = left;

    if (right < n && arr[right] < min)
        min = right;

    if (min != i)
    {
        swap(&arr[min], &arr[i]);
        heapify(arr, n, min);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i); // building heap rearrange array (n/2-1 signifies internal nodes as all internal nodes are from 0 to n/2-1)
    }
    for (int i = n-1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    clock_t start, end;
    double total_t;

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    start = clock();
    heapSort(arr, n);
    end = clock();

    printf("The sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    total_t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime required %f\n", total_t);
}