#include <stdio.h>
#include "algorithms.h"

int main() {
    // int A[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    // int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};   // Best case
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};      // Worst case
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    quicksort_visual(A, 0, n - 1);  // Using QuickSort on the entire array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}