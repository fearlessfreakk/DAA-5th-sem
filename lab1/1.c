// 1.1 Aim of the program: Write a program to find out the second smallest and second
// largest element stored in an array of n integers.
// Input. Size of the array is 'n' and read •n' number of elements from a disc file.
// Output: Second smallest, Second largest

#include <stdio.h>

int main(){
    printf("Enter the number of elements in the array: ");
    int n; scanf("%d", &n);
    if(n < 2) {
        printf("Array must contain at least two elements.\n");
        return 1;
    }
    int arr[n];

    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Array elements: ");
    int second_smallest = -1, second_largest = -1;
    int smallest = arr[0], largest = arr[0];

    
    for(int i=1; i<n; i++){
        if(arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        }else if(arr[i] < second_smallest || second_smallest == -1){
            second_smallest = arr[i];
        }
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] > second_largest || second_largest == -1){
            second_largest = arr[i];
        }
    }
    printf("Second smallest: %d\n", second_smallest);
    printf("Second largest: %d\n", second_largest);
    return 0;
}