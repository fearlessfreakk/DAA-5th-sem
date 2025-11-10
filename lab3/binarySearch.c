#include <stdio.h>
#include <time.h>


void insertionSort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j>0 && arr[j-1]>arr[j])
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;   
            j--;
        }
    }
}

int binarySearch(int low, int high, int arr[], int key) {
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]<key){
        return binarySearch(mid+1,high,arr,key);
    }else{
        return binarySearch(low,mid-1,arr,key);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: \n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter Key: ");
    scanf("%d",&key);
    insertionSort(arr,n);
    printf("Array sorted!\n");
    int ind = binarySearch(0,n-1,arr,key);
    if(ind!=-1){
        printf("Found %d at index : %d\n",key,ind);
    }else{
        printf("Element deos not exist\n");
    }
    return 0;
}