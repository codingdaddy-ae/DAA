#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int V;
int minKey(bool mstSet[], int key[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int graph[V][V], int parent[])
{
    printf("Edge\tWeight\n");
    for (int v = 1; v < V; v++)
    {
        printf("%d - %d\t%d\n", parent[v], v, graph[v][parent[v]]);
    }
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(mstSet, key);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST(graph, parent);
}


int main()
{
    printf("Enter the no. of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(graph);
}