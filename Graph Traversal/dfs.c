#include <stdio.h>
#define MAX 10
int n;
int adj[MAX][MAX];
int visited[MAX];
void DFS(int i)
{
    printf("%d->", i);
    visited[i]=1;
    for (int j = 0; j < n; j++)
    {
        if(adj[i][j] && !visited[j])
        {
            DFS(j);
        }
    } 
}

int main()
{
    int s;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &s);
    DFS(s);
}