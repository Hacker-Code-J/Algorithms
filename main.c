#include <stdio.h>
#include "algorithms.h"

int main() {
    int A[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Using partition on the entire array
    int pivotIndex = partition(A, 0, n - 1);

    printf("After partitioning around A[%d] = %d:\n", pivotIndex, A[pivotIndex]);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
