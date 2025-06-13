#include <stdio.h>

#define INF 99999
#define MAX 20

void printMatrix(int matrix[MAX][MAX], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[MAX][MAX], int V) {
    int dist[MAX][MAX], pred[MAX][MAX];
    
    // Initialize distance and predecessor matrices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];

            if (i == j || graph[i][j] == INF)
                pred[i][j] = -1; // No predecessor
            else
                pred[i][j] = i; // Immediate predecessor
        }
    }

    // Floyd-Warshall main loop
    for (int k = 0; k < V; k++) {
        printf("\nIteration after including vertex %d:\n", k);
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }

        printf("Distance Matrix:\n");
        printMatrix(dist, V);
        printf("Predecessor Matrix:\n");
        
        // Print predecessor matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (pred[i][j] == -1)
                    printf("%7s", "-");
                else
                    printf("%7d", pred[i][j]);
            }
            printf("\n");
        }
    }

    // Final result
    printf("\nFinal Shortest Distance Matrix:\n");
    printMatrix(dist, V);
}

int main() {
    int V, graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    printf("(Enter 0 for no edge between different vertices, 0 for diagonal)\n");
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int temp;
            scanf("%d", &temp);
            
            if (i == j)
                graph[i][j] = 0; // Diagonal must be 0
            else if (temp == 0)
                graph[i][j] = INF; // No edge between different nodes
            else
                graph[i][j] = temp; // Valid edge weight
        }
    }

    floydWarshall(graph, V);

    return 0;
}
