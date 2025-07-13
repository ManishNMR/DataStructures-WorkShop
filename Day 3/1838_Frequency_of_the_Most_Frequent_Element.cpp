// link - https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
// 1838. Frequency of the Most Frequent Element

// Input: nums = [1,2,4], k = 5
// Output: 3
// Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
// 4 has a frequency of 3.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int ans = 0;
    long curr = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        long target = nums[right];
        curr += target;
        while ((right - left + 1) * target - curr > k) {
            curr -= nums[left];
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Most Frequency: "<<maxFrequency(v,k)<<endl;
    return 0;
}

/*
1838. Frequency of the Most Frequent Element
@author: nmanish_0128
*/