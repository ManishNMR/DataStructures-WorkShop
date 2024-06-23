
# Sliding Window Technique in C++

## Overview

The sliding window technique is used for solving problems that involve finding a maximum or minimum value within a subarray or some other defined window of a sequential data structure like an array or string. It optimizes the process of checking all contiguous subarrays by efficiently calculating the desired value as the window slides from the beginning to the end of the sequence.

### Key Concepts

- **Window**: A contiguous subarray or substring of fixed size within the larger sequence.
- **Slide**: Moving the window from the beginning towards the end of the sequence, one element at a time.
- **Optimization**: Typically improves efficiency from O(n^2) to O(n) by reusing computations from the previous window rather than recalculating from scratch.

## Applications

The sliding window technique is commonly used in scenarios such as:

- Finding the maximum or minimum value in all contiguous subarrays of a specified size.
- Finding subarrays satisfying a given condition (e.g., sum, product, substring properties).
- Optimizing problems involving two pointers or nested loops.

## Implementation in C++

### Example Problem: Maximum Sum Subarray of Size K

Given an array of integers `nums` and an integer `k`, find the maximum sum of any contiguous subarray of size `k`.

#### Approach

1. **Initial Window Sum**: Compute the sum of the first `k` elements to initialize.
2. **Sliding the Window**: Slide the window one element at a time from left to right:
   - Subtract the element that is left out of the window.
   - Add the new element that comes into the window.
3. **Track Maximum Sum**: Keep track of the maximum sum encountered during the sliding process.

#### Example Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int maxSumSubarrayOfSizeK(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k || k <= 0) return -1; // Handle edge cases
    
    // Compute sum of the first window
    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }
    
    // Initialize maximum sum
    int maxSum = windowSum;
    
    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i - k]; // Slide the window
        maxSum = max(maxSum, windowSum);    // Update maximum sum
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int maxSum = maxSumSubarrayOfSizeK(nums, k);
    cout << "Maximum sum of subarray of size " << k << ": " << maxSum << endl;
    return 0;
}
```

#### Explanation

- **maxSumSubarrayOfSizeK**: This function implements the sliding window approach to find the maximum sum of any subarray of size `k`.
- **Window Management**: It initializes the window sum with the first `k` elements, then slides the window across the array while updating the sum efficiently.
- **Complexity**: The time complexity of this approach is O(n), where n is the size of the input array `nums`.

## Conclusion

The sliding window technique is a powerful tool in algorithm design for efficiently solving problems involving contiguous subarrays or substrings. It reduces unnecessary computation by reusing results from previous calculations, thereby improving performance compared to naive approaches. When implemented correctly, it offers an optimal solution to a wide range of problems in competitive programming and real-world applications.

## @author: nmanish_0128
