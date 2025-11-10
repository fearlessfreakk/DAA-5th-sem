#include <stdio.h>

int main() {
    printf("Enter the array size: ");
    int n; scanf("%d", &n);

    int arr[n], prefixSum[n];

    printf("Input elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + arr[i];

    printf("Output Array: ");
    for (int i = 0; i < n; i++) printf("%d ", prefixSum[i]);

    printf("\n");

    return 0;
}
