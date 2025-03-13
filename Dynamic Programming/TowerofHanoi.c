// A denotes "from-rod", B denotes "to_rod".
#include <stdio.h>
#include <time.h>

void toh(int n, char A, char B, char C)
{
    if (n > 0)
    {
        toh(n - 1, A, C, B);
        printf("\nMoving %d disk from %c to %c", n, A, C);
        toh(n - 1, B, A, C);
    }
}
int main()
{
    int n;
    char A, B, C;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    clock_t start, end;
    double total_t;
    start = clock();
    toh(n, 'A', 'B', 'C');
    end = clock();
    total_t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime required: %.9f", total_t);
    return 0;
}