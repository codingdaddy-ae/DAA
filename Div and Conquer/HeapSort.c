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
        swap(arr[min], arr[i]);
    }

    heapify(arr, n, min);
}

void heapsort(int arr[], int n)
{
    for (int i = n/2-1; i>=0; i--)
    {
        heapify(arr, n, i) //building heap rearrange array (n/2-1 signifies internal nodes as all internal nodes are )
    }
}