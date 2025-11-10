#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int i = low + 1, j = high;
    int pivot = arr[low];

    while (1) {
        while (i <= high && arr[i] < pivot) i++;
        while (j >= low && arr[j] > pivot) j--;

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        } else {
            int temp = arr[low];
            arr[low] = arr[j];
            arr[j] = temp;
            return j;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int q = partition(arr, low, high);
        quickSort(arr, low, q - 1);
        quickSort(arr, q + 1, high);
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
    quickSort(arr, 0, n - 1);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Best Case: %f seconds\n", cpuTimeUsed);

    // Worst Case: Reverse Sorted
    for (int i = 0; i < n; i++) arr[i] = n - i - 1;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Worst Case: %f seconds\n", cpuTimeUsed);

    // Average Case: Random Order
    srand(time(NULL));
    for (int i = 0; i < n; i++) arr[i] = rand() % n;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Average Case: %f seconds\n", cpuTimeUsed);

    free(arr);
    return 0;
}
