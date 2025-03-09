#include <stdio.h>
#include <time.h>

int fib_dynamic(int n, int fib [n])
{
    if (n <= 1)
    return n;
    fib [0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
int main()
{
    int n;
    printf("Enter the number of fibonacci series: ");
    scanf("%d", &n);
    int arr[n];
    clock_t start, end;
    double total_t;
    start = clock();
    printf("The fibonacci is: %d", fib_dynamic(n, arr));
    printf("\nFibonacci Series: ");
    for(int i =  0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    end = clock();
    return 0;
}