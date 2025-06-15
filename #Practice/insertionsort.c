#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j > 0 && arr[j] > key) //compare with left
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);    
    int arr[n];
    clock_t start, end;
    printf("Taking random elements: \n ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    insertion(arr, n);
    end = clock();
    double total = (double)(end - start)/CLOCKS_PER_SEC;
    printf("sorted array\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}