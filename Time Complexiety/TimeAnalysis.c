#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, c;
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    clock_t start_time, end_time;
    FILE *file;

    // Open the file for writing
    file = fopen("sorting_results.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        if (c == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (c < 1 || c > 3) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        fprintf(file, "Sorting Algorithm: ");
        switch (c) {
            case 1:
                fprintf(file, "Bubble Sort\n");
                break;
            case 2:
                fprintf(file, "Selection Sort\n");
                break;
            case 3:
                fprintf(file, "Insertion Sort\n");
                break;
        }
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
            switch (c) {
                case 1:
                    bubbleSort(arr, n);
                    break;
                case 2:
                    selectionSort(arr, n);
                    break;
                case 3:
                    insertionSort(arr, n);
                    break;
            }
            end_time = clock();

            double cpu_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("Time taken for %d elements: %f seconds\n", n, cpu_time);
            fprintf(file, "%d\t\t%f\n", n, cpu_time);
            free(arr);
        }
        fprintf(file, "\n"); // Add a newline for separation between algorithms
    }

    fclose(file);
    return 0;
}