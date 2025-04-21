#include <stdio.h>
int dybino(int n, int k)
{
    int arr[n+1][k+1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; i++)
        {
            if (k == 0 || k == n)
            {
                return 1;
            }
            return arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}
int main()
{
    int a, b;
    printf("Enter n: ");
    scanf("%d", &a);
    printf("Enter k: ");
    scanf("%d", &b);
    printf("The binomial coefficient is: %d ", dybino(a, b));
}