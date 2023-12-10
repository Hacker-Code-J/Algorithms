#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/**
 * Prints the array A with visual markers. The subarray A[p..r] is enclosed in brackets,
 * and the pivot element is marked with "(pivot)".
 *
 * @param A The array to be printed.
 * @param p The starting index of the subarray.
 * @param r The ending index of the subarray.
 * @param pivot_index The index of the pivot element.
 */
void print_array_visual(int A[], int p, int r, int pivot_index);

/**
 * Swaps the values of two integers.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int* a, int* b);

/**
 * Partitions the subarray A[p..r] so that all elements less than or equal
 * to the pivot are to the left of the pivot and all elements greater
 * are to the right.
 *
 * @param A The array to be partitioned.
 * @param p The starting index of the subarray.
 * @param r The ending index of the subarray.
 * @return The final position of the pivot.
 */
int partition(int A[], int p, int r);

/**
 * Sorts the array A using the QuickSort algorithm.
 *
 * @param A The array to be sorted.
 * @param p The starting index.
 * @param r The ending index.
 */
void quicksort(int A[], int p, int r);
void quicksort_visual(int A[], int p, int r);

void MaxHeapify(int arr[], int n, int i);
void BuildMaxHeap(int arr[], int n);
void printHeap(int arr[], int n);

void Merge(int A[], int p, int q, int r);
void printArray(int A[], int size);

#endif // PARTITION_H
