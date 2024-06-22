// link - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
// 1493. Longest Subarray of 1's After Deleting One Element

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

#include <iostream>
#include <vector>
using namespace std;

// Sliding window approch
int longestSubarray(vector<int>& nums) {
    int window = 0;
    int zeroCount=0;
    int left = 0,right=0;
    int maxi=0;
    while(right<nums.size()){
        maxi=max(maxi,window);
        if(nums[right]==0) zeroCount++;
        right++;
        cout<<zeroCount<<right<<" "<<window<<endl;
        while(zeroCount>=2){
            if(nums[left]==0) zeroCount--;
            left++;
            window--;
        }
        window++;
    }
    maxi=max(maxi,window);
    return maxi-1;
}

// Optimal solution same as above but reduce variables
int optimalLongestSubarray(vector<int> nums){
    int zeroCount=0;
    int left = 0,right=0;
    int maxi=0;
    while(right<nums.size()){
        maxi=max(maxi,right-left);
        if(nums[right]==0) zeroCount++;
        right++;
        while(zeroCount>=2){
            if(nums[left]==0) zeroCount--;
            left++;
        }
    }
    return maxi>(right-left) ? maxi-1 : right-left-1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Longest Subarray: "<<longestSubarray(v)<<endl;
    
    return 0;
}

/*
1493. Longest Subarray of 1's After Deleting One Element
@author: nmanish_0128
*/