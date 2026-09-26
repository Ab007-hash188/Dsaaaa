#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void printHeap() {
    printf("Heap array: [");
    for (int i = 0; i < size; i++) {
        printf("%d%s", heap[i], (i == size - 1) ? "" : ", ");
    }
    printf("]\n");
}

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;

    // sift-up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

int main() {
    int scores[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(scores) / sizeof(scores[0]);

    printf("=== a) MAX HEAP INSERTION ===\n");
    for (int i = 0; i < n; i++) {
        insert(scores[i]);
        printf("Insert %3d -> ", scores[i]);
        printHeap();
    }

    printf("\nFinal Max-Heap array: ");
    printHeap();

    return 0;
}