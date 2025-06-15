#include <stdio.h>
#include <time.h>

void CoinChange(int amount, int n, int coins[], int count[])
{

    printf("\nThe original coins array(sorted): ");
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
        printf("%d, ", coins[i]);
        while (amount >= coins[i])
        {
            amount -= coins[i];
            count[i]++;
        }
    }
    if (amount != 0)
        printf("\nWe cannot make this amount with the given coin denominations!");
    else
    {
        printf("\nThe solution vector for the given coin change ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", count[i]);
        }
    }
}

void sort(int arr[], int n) // **SHOULD ALWAYS BE IN DESCENDING ORDER**
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int amount, n;
    printf("enter the number of denominations: ");
    scanf("%d", &n);
    int coins[n], count[n];
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }
    printf("Enter the amount ");
    scanf("%d", &amount);

    sort(coins, n);
    CoinChange(amount, n, coins, count);
}
