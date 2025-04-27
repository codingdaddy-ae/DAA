#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int u, v, wt;
} graph;

graph edges[MAX * MAX];
graph mst [MAX]; //to store MST edges and print the tree
int parent[MAX], rank[MAX];
int n, edgeCount = 0, mstCount=0;

// Union-findParent Parent Setup
void makeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node)
{
    if (parent[node] != node)
        parent[node] = findParent(parent[node]);
    return parent[node];
}

void Union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u == v)
        return;

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int compare(const void *a, const void *b)
{
    return ((graph *)a)->wt - ((graph *)b)->wt;
}

// Kruskal's MST
int MST()
{
    qsort(edges, edgeCount, sizeof(graph), compare);
    makeSet();

    int cost = 0;
    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        if (findParent(u) != findParent(v))
        {
            cost += edges[i].wt;
            Union(u, v);
            mst[mstCount++] = edges[i];
        }
    }
    return cost;
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int wt;
            scanf("%d", &wt);
            if (j > i && wt > 0)
            { // avoid duplicates and zero edges
                edges[edgeCount++] = (graph){i, j, wt};
            }
        }
    }
    int totalweight = MST();
    printf("Edges in Kruskal's MST: \n");
    for(int i= 0; i<mstCount; i++)
    {
        printf("%d - %d : %d\n", mst[i].u, mst[i].v, mst[i].wt);
    }
    printf("Minimum Cost of MST = %d\n", totalweight);
    return 0;
}
