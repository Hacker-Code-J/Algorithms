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

void MaxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        printHeap(arr, n); // Print the heap after each swap
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, n, i);
        printHeap(arr, n);
    }
}

void printHeap(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create L[] and R[] as temporary arrays
    int L[n1 + 1], R[n2 + 1];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Sentinel values
    int INT_MAX = 10000;
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray

    // Initial index of merged subarray
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}
// Print the current state of the array after the merge
// printf("After merging from index %d to %d: ", p, r);
// printArray(A + p, r - p + 1);