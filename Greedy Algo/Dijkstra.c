#include <stdio.h>
#include <limits.h>
#include <stdbool.h> // Include for bool

int V;
int min_distance(int dist[V], bool visited[V])
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[V])
{
    printf("Vertex \t distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // Shortest distance from src to i
    bool visited[V]; //Stores visited nodes

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false; // Use false
    }
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++)
    {
        int u = min_distance(dist, visited);
        if (u == -1) break;
        visited[u] = true; // Use true
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{
    int s;
    printf("Enter the no. of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the weighted graph \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &s);

    dijkstra(graph, s);
}