#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int low, int mid, int high, int arr[]) {
    int sz = high-low+1;
    int temp[sz];
    int left = low, right = mid+1;
    int ind = 0;
    while (left<=mid && right<=high)    
    {
        if(arr[left]<=arr[right]){
            temp[ind++] = arr[left++];
        }else{
            temp[ind++] = arr[right++];
        }
    }

    while (left<=mid)
    {
        temp[ind++] = arr[left++];
    }
    while (right<=high)
    {
        temp[ind++] = arr[right++];
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }

}
void mergeSort(int low, int high, int arr[]) {
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(low,mid,arr);
    mergeSort(mid+1,high,arr);
    merge(low,mid,high,arr);
}

int main() {
    int n = 10;
    int arr[n];
    clock_t start, end;
    double cpuTimeUsed;

    // Best Case: Already Sorted
    for (int i = 0; i < n; i++) arr[i] = i;
    start = clock();
    mergeSort(0,n-1,arr);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Best Case: %f seconds\n", cpuTimeUsed);

    // Worst Case: Reverse Sorted
    for (int i = 0; i < n; i++) arr[i] = n - i -1;
    start = clock();
    mergeSort(0,n-1,arr);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Worst Case: %f seconds\n", cpuTimeUsed);

    // Average Case: Random Order
    srand(time(NULL));
    for (int i = 0; i < n; i++) arr[i] = rand() % n;
    start = clock();
    mergeSort(0,n-1,arr);
    end = clock();
    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Average Case: %f seconds\n", cpuTimeUsed);

    return 0;
}
