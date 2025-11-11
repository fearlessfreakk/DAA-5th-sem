// https://yuminlee2.medium.com/heap-sort-algorithm-6e200dc51845

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void maxHeapify(int arr[], int i, int heapSize) {
    int l = leftChild(i);
    int r = rightChild(i);
    int largest = i;

    if (l < heapSize && arr[largest] < arr[l]) largest = l;
    if (r < heapSize && arr[largest] < arr[r]) largest = r;

    if (i != largest) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, heapSize);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, n);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, 0, i);
    }
}

int main() {
    int n = 10000; // larger n for timing
    int *arr = malloc(n * sizeof(int));
    clock_t start, end;
    double cpuTimeUsed;

    // Best Case: Already Sorted
    for (int i = 0; i < n; i++) arr[i] = i;
    start = clock();
    heapSort(arr,n);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Best Case: %f seconds\n", cpuTimeUsed);

    // Worst Case: Reverse Sorted
    for (int i = 0; i < n; i++) arr[i] = n - i - 1;
    start = clock();
    heapSort(arr,n);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Worst Case: %f seconds\n", cpuTimeUsed);

    // Average Case: Random Order
    srand(time(NULL));
    for (int i = 0; i < n; i++) arr[i] = rand() % n;
    start = clock();
    heapSort(arr,n);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Average Case: %f seconds\n", cpuTimeUsed);

    free(arr);
    return 0;
}
