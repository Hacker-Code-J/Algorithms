#include "measure.h"
#include "rotation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void rotation_measure() {
    int* arr;
        int initialSize = 10; // Starting size of the array
        int growthFactor = 5; // How much the array size increases each time
        int maxSize = 10000; // Maximum size of the array
        int newSize;

        // Initialize random number generator
        srand((unsigned int)time(NULL));

        // Allocate initial array
        arr = (int*)malloc(initialSize * sizeof(int));
        if (arr == NULL) {
            perror("Initial malloc failed");
            exit(1);
        }

        // Fill the array with random numbers and resize as needed
        for (int i = 0; i < maxSize; i++) {
            if (i >= initialSize) {
                // Time to grow the array
                newSize = initialSize + growthFactor;
                int *temp = (int*)realloc(arr, newSize * sizeof(int));
                if (temp == NULL) {
                    perror("Realloc failed");
                    free(arr);
                    exit(1);
                }
                arr = temp;
                initialSize = newSize;
            }
            // Insert random number into array
            arr[i] = rand() % 100000; // Random number between 0 and 99
            // printf("arr[%d] = %d\n", i, arr[i]);
    }
    for (int i = 0; i < 10000; i++) {
        int d = i;
        // clock_t start, end;
        // double cpu_time_used;
        struct timespec start, end;
        double elapsed_time;


        // Create copies of the array for each test
        int *jugglingArr = malloc(maxSize * sizeof(int));
        int *blockSwapArr = malloc(maxSize * sizeof(int));
        int *reverseArr = malloc(maxSize * sizeof(int));
        if (!jugglingArr || !blockSwapArr || !reverseArr) {
            perror("Array allocation failed");
            free(arr);
            exit(1);
        }

        // Juggling Rotation Test
        memcpy(jugglingArr, arr, maxSize * sizeof(int));
        // start = clock();
        clock_gettime(CLOCK_MONOTONIC, &start);
        jugglingRotation(jugglingArr, maxSize, d);
        // end = clock();
        clock_gettime(CLOCK_MONOTONIC, &end);
        // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
        elapsed_time = (elapsed_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        // printf("Juggling Rotation took %f seconds\n", cpu_time_used);
        printf("%.3f\n", elapsed_time*1000000);
        free(jugglingArr); // Free the copy after use

        // Block Swap Rotation Test
        memcpy(blockSwapArr, arr, maxSize * sizeof(int));
        // start = clock();
        clock_gettime(CLOCK_MONOTONIC, &start);
        blockSwapRotate(blockSwapArr, maxSize, d);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
        elapsed_time = (elapsed_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        printf("%.3f\n", elapsed_time*1000000);
        // end = clock();
        // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        // printf("Block Swap Rotation took %f seconds\n", cpu_time_used);
        free(blockSwapArr); // Free the copy after use

        // Reversal Rotation Test
        memcpy(reverseArr, arr, maxSize * sizeof(int));
        // start = clock();
        clock_gettime(CLOCK_MONOTONIC, &start);
        ReverseRotate(reverseArr, maxSize, d);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
        elapsed_time = (elapsed_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        printf("%.3f\n", elapsed_time*1000000);
        // end = clock();
        // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        // printf("Reversal Rotation took %f seconds\n", cpu_time_used);
        free(reverseArr); // Free the copy after use
    }
    // Free the original array
    free(arr);
}