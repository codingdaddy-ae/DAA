#include <stdio.h>
#include <time.h>
#define MAX 50
int arr[MAX];
void Merge(int arr[], int lb, int mid, int ub)
{
    int i , j, k;
    int n1 = mid-lb+1;
    int n2 = ub - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[lb+i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = lb;
    while (i< n1 && j<n2)
    {
        if (L[i] < R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while (i<n1)
    {
        arr[k++]=L[i++];
    }
    while (j<n2)
    {
        arr[k++]=R[j++];
    }
}


void MergeSort(int arr[], int lb, int ub)
{
    if (lb < ub) {
        int mid = (lb +ub)/2;
        MergeSort(arr,lb, mid);
        MergeSort(arr, mid+1, ub);
        Merge(arr, lb, mid, ub);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    clock_t start, end;
    double total_t;
 
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    start=clock();
    MergeSort(arr, 0, n - 1);
    end=clock();
   
    printf("The sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    total_t =(double)(end -start)/CLOCKS_PER_SEC;
    printf("\nTime required %f\n", total_t);
}