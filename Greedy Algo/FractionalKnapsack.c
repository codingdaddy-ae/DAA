#include <stdio.h>

// Your swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(int n, int v[], int w[], float r[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (r[i] < r[j]) {
                swap(&v[i], &v[j]);    // Using swap function
                swap(&w[i], &w[j]);    // Using swap function
                // For float ratio
                float temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
    }
}

float knapsack(int cap, int n, int v[], int w[], float r[]) {
    float val = 0;
    for (int i = 0, cw = 0; i < n; i++) {
        if (cw + w[i] <= cap) {
            cw += w[i];
            val += v[i];
            printf("Item %d: Full (1.00)\n", i+1);
        } else {
            float f = (float)(cap - cw)/w[i];
            val += v[i]*f;
            printf("Item %d: Partial (%.2f)\n", i+1, f);
            break;
        }
    }
    return val;
}

int main() {
    int n, cap;
    printf("Enter items count and capacity: ");
    scanf("%d %d", &n, &cap);
    
    int v[n], w[n];
    float r[n];
    printf("Enter (value weight) for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i], &w[i]);
        r[i] = (float)v[i]/w[i];
    }
    
    sortItems(n, v, w, r);
    printf("Max value: %.2f\n", knapsack(cap, n, v, w, r));
    return 0;
}