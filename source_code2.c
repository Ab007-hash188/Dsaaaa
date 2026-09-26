#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    printf("]\n");
}

int partition(int arr[], int n, int low, int high) {
    int pivot = arr[high];
    printf("  Partition range [%d:%d], pivot=%d\n", low, high, pivot);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps++;
                printf("    swap idx%d<->idx%d: ", i, j);
                printArray(arr, n);
            }
        }
    }
    if (i + 1 != high) {
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swaps++;
    }
    printf("    place pivot at idx%d: ", i + 1);
    printArray(arr, n);
    return i + 1;
}

void quickSort(int arr[], int n, int low, int high) {
    if (low < high) {
        int p = partition(arr, n, low, high);
        quickSort(arr, n, low, p - 1);
        quickSort(arr, n, p + 1, high);
    }
}

int main() {
    int arr[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== b) QUICK SORT (Lomuto partition, last element as pivot) ===\n");
    printf("Initial array: ");
    printArray(arr, n);

    quickSort(arr, n, 0, n - 1);

    printf("\nFinal sorted array: ");
    printArray(arr, n);
    printf("Quick Sort -> comparisons: %d, swaps: %d\n", comparisons, swaps);

    return 0;
}