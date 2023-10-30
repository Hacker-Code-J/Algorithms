#ifndef ALGORITHMS_H
#define ALGORITHMS_H

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

#endif // PARTITION_H
