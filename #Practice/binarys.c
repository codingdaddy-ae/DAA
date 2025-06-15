#include <stdio.h>
void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }   
        }
    }
}
int binary(int arr[], int left, int right, int k)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (k == arr[mid]){
            printf("target found at index: %d", mid);
            return mid;
        }
        else if(k < arr[mid])
            return binary(arr,left, mid-1, k);
        else
           return binary(arr,mid+1, right, k);
        }
    else 
        printf("\nTarget not found! ");
        return -1;
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
    binary(arr, 0, n, k);

}