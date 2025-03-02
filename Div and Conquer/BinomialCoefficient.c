#include <stdio.h>

int binomial(int n, int k)
{
    if (k==0 || k==n)
    {
        return 1;
    }
    return binomial(n-1, k-1) + binomial(n-1, k);
}

int main()
{
    int a , b;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);
    printf("The binomial co-efficient of the two numbers is: %d", binomial(a,b));
    return 0;

}