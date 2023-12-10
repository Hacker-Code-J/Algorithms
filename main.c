#include <stdio.h>
#include "algorithms.h"

void MaxHeapify_TEST() {
    int arr[] = {3, 2, 15, 5, 4, 45, 6, 7, 51, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Heap: \n");
    printHeap(arr, n);
    printf("---------------------------\n");

    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);

    printf("Max-Heap: \n");
    printHeap(arr, n);
}
void BuildMaxHeap_TEST() {
    int arr[] = {3, 2, 15, 5, 4, 45, 6, 7, 51, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printHeap(arr, n);
    printf("---------------------------\n");

    BuildMaxHeap(arr, n);

    printf("Max-Heap: \n");
    printHeap(arr, n);
}

// Driver code to test the Merge function
void Merge_TEST() {
    int A[] = {12, 11, 13, 5, 6, 7};
    int arraySize = sizeof(A) / sizeof(A[0]);


    printf("Original Array: \n");
    printArray(A, arraySize);
    printf("---------------------------\n");

    // Assuming p, q, and r are such that they divide the array into two halves
    int p = 0, q = (arraySize / 2) - 1, r = arraySize - 1;

    Merge(A, p, q, r);

    printf("Sorted array is \n");
    printArray(A, arraySize);
}

int main() {
    // MaxHeapify_TEST();
    // printf("\n");
    // BuildMaxHeap_TEST();

    Merge_TEST();


    // // int A[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    // // int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};   // Best case
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};      // Worst case
    // int n = sizeof(A) / sizeof(A[0]);

    // printf("Original array: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", A[i]);
    // }
    // printf("\n");

    // quicksort_visual(A, 0, n - 1);  // Using QuickSort on the entire array

    // printf("Sorted array: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", A[i]);
    // }
    // printf("\n");

    return 0;
}