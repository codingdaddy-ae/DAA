#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}

int main()
{
    int n;
    clock_t start, end;
    FILE *file;
    fopen("insertion_sort_results.txt", "w");
    if (file = NULL)
    {
        printf("Error in opening file \n");
        return -1;
    }
    
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    fprintf("Time taken by Insertion sort\n");
    fprintf("Input Size \t\t Time taken\n");

    for (int i = 0; i < 6; i++)
    {
        n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory Allocation failed!\n ");
            return -1;
        }

        for (int j = 0; j < n; j++)
        {
            arr[j] = rand();
        }
        start = clock();
        insertion(arr, n);
        end = clock();
        double total_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken for %d elements: %f\n", n, total_time);
        free(arr);
    }
}