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


int ternarySearch(int low, int high, int arr[], int key) {
    if(low>high) return -1;
    
    int mid1 = low + (high-low)/3;
    int mid2 = high - (high-low)/3;

    if(arr[mid1]==key){
        return mid1;
    }else if(arr[mid2]==key){
        return mid2;
    }else if(key<arr[mid1]){
        return ternarySearch(low,mid1-1,arr,key);
    }else if(key>arr[mid2]){
        return ternarySearch(mid2+1,high,arr,key);
    }else{
        return ternarySearch(mid1+1,mid2-1,arr,key);
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
    int ind = ternarySearch(0,n-1,arr,key);
    if(ind!=-1){
        printf("Found %d at index : %d\n",key,ind);
    }else{
        printf("Element deos not exist\n");
    }
    return 0;
}

// #include <stdio.h>
// #include <time.h>

// int ternarySearch(int low, int high, int arr[], int key) {
//     if(low>high) return -1;
    
//     int mid1 = low + (high-low)/3;
//     int mid2 = high - (high-low)/3;

//     if(arr[mid1]==key){
//         return mid1;
//     }else if(arr[mid2]==key){
//         return mid2;
//     }else if(key<arr[mid1]){
//         return ternarySearch(low,mid1-1,arr,key);
//     }else if(key>arr[mid2]){
//         return ternarySearch(mid2+1,high,arr,key);
//     }else{
//         return ternarySearch(mid1+1,mid2-1,arr,key);
//     }
// }

// int main() {
//     int n = 10000;
//     int arr[n];
//     clock_t start, end;
//     double cpuTimeUsed;
//     int key;
//     printf("Enter Key:");
//     scanf("%d",&key);
    
//     for (int i = 0; i < n; i++) arr[i] = i;
//     start = clock();
//     int ind = ternarySearch(0,n-1,arr,key);
//     end = clock();
//     cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
//     if(ind!=-1){
//         printf("Key found at index %d : %d\n",key,arr[ind]);
//     }else{
//         printf("Key not found\n");
//     }
//     printf("TIme taken: %f seconds\n", cpuTimeUsed);


//     return 0;
// }
