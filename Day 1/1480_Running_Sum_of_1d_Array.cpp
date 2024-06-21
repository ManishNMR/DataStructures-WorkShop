// Link- https://leetcode.com/problems/running-sum-of-1d-array/description/
// 1480. Running Sum of 1d Array

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

#include <iostream>
#include <vector>

using namespace std;

// using Prefix_Sum
vector<int> runningSum(vector<int>&nums){
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        ans.push_back(nums[i]+ans.back());
    }
    return ans;
}

// Optimal Solution
vector<int> optimalRunningSum(vector<int>& nums) {
       for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
       }
        return nums;
}

int main(){
    int t;
    cin>>t;
    vector<int>v;
    for(int i=0;i<t;i++){
        cin>>v[i];
    }

    vector<int> ans;

    ans = runningSum(v);
    cout<<"Running Sum: ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    
    ans = optimalRunningSum(v);
    cout<<"Optimal Running Sum: ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

/*
1480. Running Sum of 1d Array
@author: nmanish_0128
*/