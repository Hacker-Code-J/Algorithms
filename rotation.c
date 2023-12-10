#include "rotation.h"

// Function to calculate GCD
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

// Function to rotate the array
void jugglingRotation(int arr[], int n, int d) {
    d = d % n;  // In case d >= n
    int gcd_val = gcd(n, d);
    for (int i = 0; i < gcd_val; i++) {
        // Move i-th values of blocks
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + d;
            if (k >= n) {
                k = k - n;
            }
            if (k == i) {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void blockSwap(int A[], int start1, int start2, int blockSize) {
    int i, temp;
    for (i = 0; i < blockSize; i++) {
        temp = A[start1 + i];
        A[start1 + i] = A[start2 + i];
        A[start2 + i] = temp;
    }
}

void blockSwapRotate(int arr[], int n, int d) {
    int i, j, p;
    if (d == 0 || d == n) {
        return; // No rotation needed
    }

    i = p = d;
    j = n - d;
    while (i != j) {
        if (i > j) {
            blockSwap(arr, p - i, p, j);
            i -= j;
        } else {
            blockSwap(arr, p - i, p + j - i, i);
            j -= i;
        }
    }
    blockSwap(arr, p - i, p, i);
}

// Function to reverse the elements of the array from index 'start' to 'end'
void reverse(int arr[], int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array 'arr' of size 'n' by 'd' elements to the left
void ReverseRotate(int arr[], int n, int d) {
    if (d == 0 || d == n) return; // No rotation needed
    d = d % n; // In case the rotation count is greater than array size
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
