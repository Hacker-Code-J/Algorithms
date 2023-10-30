# QuickSort Complexity Analysis

## 1. Computational Complexity:

- **Best Case: \(O(n \log n)\)**
  - This occurs when each partitioning step splits the array into roughly equal halves, leading to a logarithmic number of recursive calls.

- **Average Case: \(O(n \log n)\)**
  - On average, even if the splits aren't perfectly in half, the algorithm tends to have a logarithmic depth of recursive calls.

- **Worst Case: \(O(n^2)\)**
  - This occurs when the array is already sorted or reverse sorted, and every partitioning step splits the array into one element and the rest of the array. This can be mitigated with better pivot selection strategies like using the median of three method.

## 2. Space Complexity:

The primary space consumption in QuickSort is due to the recursive call stack.

- **Best and Average Case: \(O(\log n)\)**
  - The best and average cases correspond to the height of the balanced or near-balanced recursion tree, which is logarithmic in the size of the input.

- **Worst Case: \(O(n)\)**
  - The worst case corresponds to a skewed recursion tree where every level has only one node. This is essentially the depth of the recursion.

> **Notes:**
> 1. The space complexity mentioned here does not include the input space (i.e., the space taken by the array to be sorted).
> 2. Using iterative methods with a manual stack or tail recursion optimizations can reduce the space complexity.
> 3. Randomized QuickSort (where a pivot is chosen randomly) tends to perform closer to the average case in practice, mitigating the worst-case scenario.