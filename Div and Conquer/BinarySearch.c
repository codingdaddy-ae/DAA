#include <stdio.h>
#include <time.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary(int arr[], int left, int right, int target
{
        if (left <= right)
    {
        int mid = left + (right - left) / 2; // Find middle index
        if (target == arr[mid])
            return mid; // Target found
        if (arr[mid] < target)
            return binary(arr, mid + 1, right, target);
        else
            return binary(arr, left, mid - 1, target);
    }
    return -1; // Target not found
}

int main()
{
    int n, k;
    int flag;
   
    printf("Enter the size of the array: ");
    scanf("%d", &n);
   
    clock_t start, end;
    double total_t;
    int arr[n]; // Dynamic array
   
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: \n");
    scanf("%d", &k);
   
    start = clock();
    sort(arr, n);
    flag = binary(arr, 0, n - 1, k);
    if (flag != -1)
        printf("Target found \n");
    else
        printf("Not found\n");
    end = clock();
   
    total_t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required = %f seconds\n", total_t);
   
    return 0;
}
