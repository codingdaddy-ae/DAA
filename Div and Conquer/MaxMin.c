#include <stdio.h>
#include <time.h>

int Max(int a, int b) {
    return (a > b) ? a : b;
}
int Min(int a, int b) {
    return (a < b) ? a : b;
}
void MaxMin(int arr[], int x, int y, int *max1, int *min1) {
    if (y - x <= 1) {
        *max1 = Max(arr[x], arr[y]);
        *min1 = Min(arr[x], arr[y]);
    } else {
        int mid = (x + y) / 2;
        int max1_left, min1_left;
        MaxMin(arr, x, mid, &max1_left, &min1_left);
       
        int max1_right, min1_right;
        MaxMin(arr, mid + 1, y, &max1_right, &min1_right);
       
        *max1 = Max(max1_left, max1_right);
        *min1 = Min(min1_left, min1_right);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    clock_t start,end;
    double total_t;
 
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    start=clock();
    int max_value, min_value;
    MaxMin(arr, 0, n - 1, &max_value, &min_value);
    end=clock();
   
   
    printf("Maximum: %d\n", max_value);
    printf("Minimum: %d\n", min_value);
    total_t =(double)(end -start)/CLOCKS_PER_SEC;
    printf("Time required %f", total_t);
    return 0;
}