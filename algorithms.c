#include "algorithms.h"

#include <stdio.h>

void print_array_visual(int A[], int p, int r, int pivot_index) {
    for (int i = 0; i <= r; i++) {
        if (i == p)
            printf("[ ");
        printf("%d ", A[i]);
        if (i == pivot_index)
            printf("(pivot) ");
        if (i == r)
            printf("] ");
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];  // Choose the pivot as the last element
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);  // Place the pivot in its correct position
    return i + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);  // Partition the array
        quicksort(A, p, q - 1);      // Recursively sort the left subarray
        quicksort(A, q + 1, r);      // Recursively sort the right subarray
    }
}

void quicksort_visual(int A[], int p, int r) {
    if (p < r) {
        printf("Before partitioning:\n");
        print_array_visual(A, p, r, r);
        int q = partition(A, p, r);
        printf("After partitioning:\n");
        print_array_visual(A, p, r, q);
        printf("\n");
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
