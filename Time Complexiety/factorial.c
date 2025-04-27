#include <stdio.h>
#include <time.h>

int fact(int n)
{
    if (n == 1)
       return n;
    return fact(n-1)*n;   
}
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    clock_t start, end;
    double total_t;
    start = clock();
    printf("The factorial is: %d", fact(n));
    end = clock();
    total_t=(double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime required: %f", total_t);
    return 0;
}