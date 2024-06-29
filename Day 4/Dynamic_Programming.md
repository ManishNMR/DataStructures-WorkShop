# Dynamic Programming in C++

Dynamic programming (DP) is a technique for solving problems by breaking them down into simpler subproblems and storing the results of these subproblems to avoid redundant computations. It's particularly useful for optimization problems where decisions need to be made at various stages.

1. **Basic Concepts**: What is dynamic programming?
2. **Types of Dynamic Programming**: Top-Down and Bottom-Up approaches.
3. **Common Patterns**: How to recognize problems that can be solved using DP.
4. **Implementation**: How to implement DP solutions in C++.
5. **Examples**: Classic DP problems and their C++ solutions.


## 1. Basic Concepts

### What is Dynamic Programming?

Dynamic Programming is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable where the problem can be divided into overlapping subproblems which can be solved independently.

**Key ideas in DP:**
- **Optimal Substructure**: The optimal solution of the problem can be constructed from the optimal solutions of its subproblems.
- **Overlapping Subproblems**: The problem can be broken down into subproblems which are reused several times.

### Memorization and Tabulation

- **Memoization**: Top-Down approach where results of subproblems are stored in a table to avoid redundant calculations.
- **Tabulation**: Bottom-Up approach where the problem is solved by solving all possible subproblems and storing their results.

## 2. Types of Dynamic Programming

### Top-Down Approach (Memoization)

In this approach, we solve the problem recursively and store the results of the subproblems in a table (usually an array or a hash map). When we need the result of a subproblem, we check the table first to see if it's already computed.

**Advantages**:
- Easy to implement with recursion.
- Avoids recomputation by storing the results of subproblems.

**Example**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 10;
    vector<int> memo(n + 1, -1);
    cout << "Fibonacci of " << n << " is " << fib(n, memo) << endl;
    return 0;
}
```

### Bottom-Up Approach (Tabulation)

In this approach, we solve the smallest subproblems first and use their results to build up the solution to the original problem. This approach often uses iterative loops and a table to store results.

**Advantages**:
- Often more space-efficient.
- Avoids function call overhead.

**Example**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci of " << n << " is " << fib(n) << endl;
    return 0;
}
```

## 3. Common Patterns

### Identifying DP Problems

1. **Optimal Substructure**: Can you express the solution in terms of solutions to subproblems?
2. **Overlapping Subproblems**: Do subproblems recur multiple times?

### Problem Types

- **Fibonacci Sequence**: Demonstrates the basic concept of DP.
- **Knapsack Problem**: Optimization problem with constraints.
- **Longest Common Subsequence**: Matching patterns in sequences.
- **Coin Change Problem**: Finding ways to achieve a sum with given denominations.

## 4. Implementation

### Steps to Implement DP

1. **Define the Subproblem**: Identify and define the subproblems.
2. **Determine State Variables**: Decide what variables to store in your DP table.
3. **Formulate Recurrence Relation**: Develop the relation that connects subproblems.
4. **Initialization**: Initialize the base cases in your DP table.
5. **Solve and Build the Solution**: Use the recurrence relation to fill the table and derive the solution.

### Example: 0/1 Knapsack Problem

**Problem**: Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack.

**Recursive Approach**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, const vector<int> &wt, const vector<int> &val, int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W) return knapSack(W, wt, val, n - 1);
    return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
               knapSack(W, wt, val, n - 1));
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << "Maximum value in Knapsack = " << knapSack(W, wt, val, n) << endl;
    return 0;
}
```

**DP Approach**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, const vector<int> &wt, const vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << "Maximum value in Knapsack = " << knapSack(W, wt, val, n) << endl;
    return 0;
}
```

## 5. Examples

### Longest Common Subsequence

**Problem**: Given two sequences, find the length of the longest subsequence present in both of them.

**DP Solution**:
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(const string &X, const string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << "Length of LCS is " << lcs(X, Y) << endl;
    return 0;
}
```

### Coin Change Problem

**Problem**: Given a value `N`, find the minimum number of coins that make a sum `N` given an infinite supply of coins of given denominations.

**DP Solution**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int minCoins(const vector<int> &coins, int V) {
    vector<int> dp(V + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= V; i++) {
        for (auto coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int V = 11;
    cout << "Minimum coins required is " << minCoins(coins, V) << endl;
    return 0;
}
```

## Conclusion

Dynamic Programming is a powerful

 technique for solving optimization problems by storing the results of subproblems. In C++, this involves using recursion with memoization or iterative loops with tabulation. Understanding the basic principles and patterns in DP can greatly improve your problem-solving skills for complex algorithmic challenges.

 Understanding the time complexity of dynamic programming solutions is crucial for analyzing their efficiency. Here’s a detailed breakdown of the time complexity in dynamic programming:

## Time Complexity in Dynamic Programming

### General Principles

1. **Number of Subproblems**: The total number of distinct subproblems determines the primary factor of the time complexity.
2. **Time per Subproblem**: The amount of time required to solve each subproblem.

The total time complexity is typically the product of the number of subproblems and the time required to solve each subproblem.

### Top-Down Approach (Memoization)

In the top-down approach, you typically use recursion with memoization to avoid redundant calculations.

- **Number of Subproblems**: The complexity is determined by the total number of unique subproblems.
- **Time per Subproblem**: Each subproblem is solved once, and looking up a stored result is generally `O(1)`.

**Example: Fibonacci Sequence (Memoized)**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 10;
    vector<int> memo(n + 1, -1);
    cout << "Fibonacci of " << n << " is " << fib(n, memo) << endl;
    return 0;
}
```
- **Time Complexity**: `O(n)`
  - There are `n` unique subproblems, each solved once.

### Bottom-Up Approach (Tabulation)

In the bottom-up approach, you iteratively solve subproblems starting from the smallest ones and build up to the solution.

- **Number of Subproblems**: Determined by the total number of possible subproblems that need to be solved.
- **Time per Subproblem**: Generally `O(1)` if each subproblem is solved directly using previously computed values.

**Example: Fibonacci Sequence (Tabulated)**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci of " << n << " is " << fib(n) << endl;
    return 0;
}
```
- **Time Complexity**: `O(n)`
  - Computation for each `dp[i]` takes `O(1)`, with `n` iterations.

### Detailed Time Complexity Analysis for Common Problems

#### 0/1 Knapsack Problem

**Problem**: Given `n` items with weights and values, find the maximum value you can carry in a knapsack of capacity `W`.

**DP Approach**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, const vector<int> &wt, const vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << "Maximum value in Knapsack = " << knapSack(W, wt, val, n) << endl;
    return 0;
}
```
- **Time Complexity**: `O(n * W)`
  - `n` items and `W` weight capacity create a table of size `n * W`.
- **Space Complexity**: `O(n * W)`

#### Longest Common Subsequence

**Problem**: Find the length of the longest subsequence common to two sequences.

**DP Solution**:
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(const string &X, const string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << "Length of LCS is " << lcs(X, Y) << endl;
    return 0;
}
```
- **Time Complexity**: `O(m * n)`
  - `m` and `n` are the lengths of the two strings.
- **Space Complexity**: `O(m * n)`

#### Coin Change Problem

**Problem**: Find the minimum number of coins required to make a sum `V` using given denominations.

**DP Solution**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int minCoins(const vector<int> &coins, int V) {
    vector<int> dp(V + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= V; i++) {
        for (auto coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int V = 11;
    cout << "Minimum coins required is " << minCoins(coins, V) << endl;
    return 0;
}
```
- **Time Complexity**: `O(V * n)`
  - `V` is the sum, and `n` is the number of coin denominations.
- **Space Complexity**: `O(V)`

### Optimizations and Variations

1. **Space Optimization**: Often, we can reduce space complexity by only storing necessary data (e.g., using a 1D array instead of a 2D array).
2. **Iterative vs. Recursive**: Iterative implementations usually have better space efficiency than recursive ones due to function call overhead in recursion.
3. **Parallelism**: Some DP problems can be parallelized, though this is more advanced and problem-specific.

### Summary Table

| **Problem Type**            | **Example**                         | **Time Complexity** | **Space Complexity** |
|-----------------------------|-------------------------------------|---------------------|----------------------|
| Fibonacci Sequence          | Basic recursive or iterative        | `O(n)`              | `O(n)` or `O(1)`     |
| 0/1 Knapsack Problem        | Maximum value in a knapsack         | `O(n * W)`          | `O(n * W)`           |
| Longest Common Subsequence  | Matching sequences                  | `O(m * n)`          | `O(m * n)`           |
| Coin Change Problem         | Minimum coins for a given sum       | `O(V * n)`          | `O(V)`               |

Understanding the time complexity of dynamic programming solutions helps in selecting the most efficient approach and optimizing the performance of algorithms for real-world applications.


## @author: nmanish_0128
