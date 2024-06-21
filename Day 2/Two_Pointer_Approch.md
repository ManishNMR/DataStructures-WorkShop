## Two Pointer Approach

### Overview

The Two Pointer approach is a popular algorithmic technique used to solve problems efficiently by employing two pointers (or indices) to traverse and manipulate data structures such as arrays or linked lists. This method is particularly useful in scenarios involving searching, sorting, and partitioning where operations can be performed in linear or sub-linear time.

### Common Use Cases

1. **Finding pairs in a sorted array** that sum up to a given value.
2. **Detecting palindromes** by comparing characters from both ends.
3. **Merging sorted arrays** into a single sorted array.
4. **Removing duplicates** from a sorted array.
5. **Partitioning arrays** into subarrays based on certain conditions.

### How It Works

The Two Pointer technique typically involves two pointers moving towards each other or in the same direction based on the problem requirements. Here are the general scenarios:

1. **Opposite Direction Pointers**: Start from both ends of the array and move towards the center.
2. **Same Direction Pointers**: Start from the beginning and move towards the end, but at different speeds or with different rules for each pointer.

### Example Patterns

#### 1. Finding a Pair with a Given Sum

**Problem**: Given a sorted array, find two numbers that sum to a target value.

**Algorithm**:
1. Initialize two pointers, one at the beginning (`left`) and one at the end (`right`).
2. Calculate the sum of the elements at these pointers.
3. If the sum matches the target, return the indices or the values.
4. If the sum is less than the target, move the `left` pointer to the right to increase the sum.
5. If the sum is more than the target, move the `right` pointer to the left to decrease the sum.
6. Continue until the pointers meet or the target is found.

```python
def find_pair_with_sum(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return left, right  # or return arr[left], arr[right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    return None
```

#### 2. Removing Duplicates from a Sorted Array

**Problem**: Given a sorted array, remove duplicates in-place such that each element appears only once.

**Algorithm**:
1. Use two pointers: `write_index` to track the position for writing unique elements and `read_index` to scan through the array.
2. If the element at `read_index` is different from the element at `write_index - 1`, copy it to `write_index` and increment `write_index`.
3. Continue until the end of the array is reached.

```python
def remove_duplicates(arr):
    if not arr:
        return 0
    write_index = 1
    for read_index in range(1, len(arr)):
        if arr[read_index] != arr[write_index - 1]:
            arr[write_index] = arr[read_index]
            write_index += 1
    return write_index
```

#### 3. Container With Most Water

**Problem**: Given an array of non-negative integers representing the heights of bars in a histogram, find two lines that together with the x-axis forms a container that holds the most water.

**Algorithm**:
1. Initialize two pointers at both ends of the array.
2. Calculate the area formed by the lines at these pointers and the width between them.
3. Move the pointer pointing to the shorter line towards the other end to potentially find a taller line and thus a larger area.
4. Continue until the pointers meet.

```python
def max_area(heights):
    left, right = 0, len(heights) - 1
    max_area = 0
    while left < right:
        width = right - left
        height = min(heights[left], heights[right])
        max_area = max(max_area, width * height)
        if heights[left] < heights[right]:
            left += 1
        else:
            right -= 1
    return max_area
```

### Complexity Analysis

- **Time Complexity**: Typically \( O(n) \) since each pointer usually traverses the array once.
- **Space Complexity**: Typically \( O(1) \) as no extra space is required beyond the input.

### Advantages

- **Efficiency**: Often more efficient than brute force methods.
- **Simplicity**: Simple and intuitive to implement for many problems.

### Disadvantages

- **Limited Scope**: Best suited for problems that can be naturally divided into two parts or involve linear traversal.

### Conclusion

The Two Pointer approach is a versatile technique for solving various algorithmic problems involving arrays and linked lists. By optimizing traversal, it provides a significant performance improvement over more naive approaches. Understanding and mastering this method can enhance your ability to solve a wide range of coding challenges efficiently.


## @author: nmanish_0128
