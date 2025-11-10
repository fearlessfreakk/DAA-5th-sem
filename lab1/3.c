// 1.3 Aim of the program: Write a program to read 'n' integers from a disc file that must
// contain some duplicate values and store them into an array. Perform the following
// operations on the array.
// a)
// Find out the total number of duplicate elements.
// b)
// Find out the most repeating element in the array.
// Input:
// Enter how many numbers you want to read from file: 15

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of values: ");
    scanf("%d", &n);

    int arr[n];
    int freq[n];

    printf("enter array elements : ");
    for (int i = 0; i < n; i++) {
        freq[i] = -1;
        scanf("%d", &arr[i]);
    }

    int duplicateCount = 0;
    int maxFreq = 0, mostRepeated;

    for (int i = 0; i < n; i++) {
        int count = 1;
        if (freq[i] != 0) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
            if (count > 1) duplicateCount++;
            if (count > maxFreq) {
                maxFreq = count;
                mostRepeated = arr[i];
            }
        }
    }

    printf("Total number of duplicate elements: %d\n", duplicateCount);
    printf("Most repeating element: %d (repeated %d times)\n", mostRepeated, maxFreq);

    return 0;
}
