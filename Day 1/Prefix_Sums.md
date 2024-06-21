## Prefix Sum in C++

### Overview

The prefix sum (also known as a cumulative sum) is an array where each element is the sum of the elements up to that index in the original array. It is a useful technique for answering range sum queries efficiently and is widely used in algorithms and data processing.

### Features

- **Efficient Range Sum Queries**: Compute the sum of elements between any two indices in constant time.
- **Simple Construction**: Build the prefix sum array in linear time.
- **Minimal Space Overhead**: Requires only an additional array of the same length as the input array.

### Example

Given an array: `[1, 2, 3, 4, 5]`

The prefix sum array would be: `[1, 3, 6, 10, 15]`

### How to Use

#### 1. Build Prefix Sum Array

To build the prefix sum array, follow these steps:

1. Initialize the first element of the prefix sum array to be the same as the first element of the input array.
2. For each subsequent element, add the current element of the input array to the previous element of the prefix sum array.

```cpp
#include <vector>
#include <iostream>

std::vector<int> buildPrefixSum(const std::vector<int>& arr) {
    std::vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}
```

#### 2. Query Sum of Any Subarray

To find the sum of elements between indices `left` and `right` (inclusive), use the prefix sum array:

- If `left == 0`, the sum is `prefixSum[right]`.
- Otherwise, the sum is `prefixSum[right] - prefixSum[left - 1]`.

```cpp
int rangeSum(const std::vector<int>& prefixSum, int left, int right) {
    if (left == 0) {
        return prefixSum[right];
    } else {
        return prefixSum[right] - prefixSum[left - 1];
    }
}
```

### Example Usage

```cpp
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> prefixSum = buildPrefixSum(arr);
    
    // Query sum from index 1 to 3 (inclusive)
    int sum = rangeSum(prefixSum, 1, 3); // Output should be 9 (2+3+4)
    std::cout << "Sum from index 1 to 3: " << sum << std::endl;
    
    return 0;
}
```

### Advantages

- **Efficiency**: After an initial O(n) preprocessing time, each range sum query can be answered in O(1) time.
- **Simplicity**: The concept and implementation are straightforward.

### Limitations

- **Static Array**: The prefix sum array needs to be recalculated if the original array is updated.
- **Space Complexity**: Requires O(n) additional space, which might be a concern for very large arrays.

### Further Enhancements

- **2D Prefix Sum**: Extend the concept to 2D arrays for querying submatrix sums.
- **Fenwick Tree**: Use Fenwick Tree (Binary Indexed Tree) for dynamic updates.

### Code Example

```cpp
#include <vector>
#include <iostream>

std::vector<int> buildPrefixSum(const std::vector<int>& arr) {
    std::vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}

int rangeSum(const std::vector<int>& prefixSum, int left, int right) {
    if (left == 0) {
        return prefixSum[right];
    } else {
        return prefixSum[right] - prefixSum[left - 1];
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> prefixSum = buildPrefixSum(arr);
    
    int sum = rangeSum(prefixSum, 1, 3); // Should output 9
    std::cout << "Sum from index 1 to 3: " << sum << std::endl;
    
    return 0;
}
```

## @author: nmanish_0128
