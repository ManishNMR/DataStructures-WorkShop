// link - https://leetcode.com/problems/min-cost-climbing-stairs/
// 746. Min Cost Climbing Stairs

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

#include <iostream>
#include <vector>
using namespace std;

// brute force
int minCostClimbingStairs(vector<int>& cost) {
    int a=0,b=0;
    for(int i=0;i<cost.size();i++){
        int c = a;
        a = b;
        b = min(c,b) + cost[i];
    }
    return min(a,b);
}

// optimal solution
int optimalMinCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << "MinCostClimbingStairs: "<< minCostClimbingStairs(cost) << endl;
    cout << "Optimal MinCostClimbingStairsOptimal: " << optimalMinCostClimbingStairs(cost) << endl; // Output: 15

    return 0;
}

/*
746. Min Cost Climbing Stairs
@author: nmanish_0128
*/