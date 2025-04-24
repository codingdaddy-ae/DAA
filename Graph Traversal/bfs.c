#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int adj[MAX][MAX], queue[MAX], visited[MAX];
int front = 0, rear = 0, n;

void bfs(int s)
{
    visited[s] = 1;
    visited[rear++] = s;

    while(front < rear)
    {
        int v = queue[front++];
        printf("%d ", &v);

        for(int i = 1; i<=n; i++)
        {
            if(adj[v][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int s;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &s);
    printf("The BFS traversal");
    bfs(s);
            
}