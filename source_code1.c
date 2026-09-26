#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    printf("]\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        comparisons++;
        if (arr[l] > arr[largest]) largest = l;
    }
    if (r < n) {
        comparisons++;
        if (arr[r] > arr[largest]) largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        swaps++;
        printf("  swap idx%d<->idx%d: ", i, largest);
        printArray(arr, n);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    printf("Initial array: ");
    printArray(arr, n);

    printf("-- Build Max Heap --\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    printf("Heap built: ");
    printArray(arr, n);

    printf("\n-- Extraction phase --\n");
    for (int end = n - 1; end > 0; end--) {
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        swaps++;
        printf("Swap root with idx%d: ", end);
        printArray(arr, n);
        heapify(arr, end, 0);
    }
}

int main() {
    int arr[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== b) HEAP SORT ===\n");
    heapSort(arr, n);

    printf("\nFinal sorted array: ");
    printArray(arr, n);
    printf("Heap Sort -> comparisons: %d, swaps: %d\n", comparisons, swaps);

    return 0;
}