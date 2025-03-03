#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int n, c;
    int sizes[] = {10, 100, 1000, 10000, 100000};
    clock_t start_time, end_time;
    FILE *file;

    // Open the file for writing
    file = fopen("sorting_results2.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
        fprintf(file, "Selection Sort\n");

        fprintf(file, "Input Size\tCPU Time (seconds)\n");

        for (int i = 0; i < 6; i++) {
            n = sizes[i];
            int *arr = (int *)malloc(n * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation failed\n");
                fclose(file);
                return -1;
            }

            // Initialize array with random numbers
            for (int j = 0; j < n; j++) {
                arr[j] = rand();
            }

            start_time = clock();
            selectionSort(arr, n);
            end_time = clock();

            double cpu_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("Time taken for %d elements: %f seconds\n", n, cpu_time);
            fprintf(file, "%d\t\t%f\n", n, cpu_time);
            free(arr);
        }
        fprintf(file, "\n"); // Add a newline for separation between algorithms
        fclose(file);
        return 0;
    }
