#include <stdio.h>
#define MAX 100

int k[MAX][MAX];
int p[MAX], wt[MAX];

int max(int a, int b)
{
    return a > b ? a : b;
}
int knapsack(int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            if (wt[i] <= w)
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]); //ekhoner maal ta + ager row er remaining weight er maal ta (ke ki nite parbo?) 
            else
                k[i][w] = k[i - 1][w];
        }
    }
    return k[n][m];
}
int main()
{
    int n, m;
    printf("Enter the no. of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);

    printf("Enter the profit and weights for each items: \n");
    for (int i = 1; i <= n; i++)
    {
        printf("Item %d Profit: ", i);
        scanf("%d", &p[i]);
        printf("Item %d Weight: ", i);
        scanf("%d", &wt[i]);
    }

    int maxProfit = knapsack(n, m);
    printf("Knapsack Table: \n");
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            printf("%d\t", k[i][w]);
        }
        printf("\n");
    }

    printf("Maxmium Profit: %d", maxProfit);
    
    int w = m;
    printf("Selected Items: ");
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (k[i][w] != k[i - 1][w])
        {
            printf("%d ", i);
            w -= wt[i];
        }
    }

    return 0;
}
