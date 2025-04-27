#include <stdio.h>
#include <limits.h>

#define MAX 10

typedef struct
{
    int src, dest, weight;
} Edge;

int n;
Edge edges[MAX];
int edgeCount;
int dist[MAX];

void BellmanFord(int src)
{
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edgeCount; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    // Checks for the -ve edge cycle
    for (int j = 0; j < edgeCount; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            printf("Graph contains negative weight cycles!");
            return;
        }
    }

    printf("\nShortest distances from node %d:\n", src);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}

int main()
{
    int s;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacencey matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int wt;
            scanf("%d", &wt);
            if (wt != 0)
            edges[edgeCount++] = (Edge){i, j, wt};        
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &s);
    BellmanFord(s);
}