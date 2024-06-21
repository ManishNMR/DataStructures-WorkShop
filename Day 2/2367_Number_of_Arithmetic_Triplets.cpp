// link - https://leetcode.com/problems/number-of-arithmetic-triplets/
// 2367. Number of Arithmetic Triplets

// Input: nums = [0,1,4,6,7,10], diff = 3
// Output: 2
// Explanation:
// (1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
// (2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
    set<int> s;
    for(int i=0;i<nums.size();i++) s.insert(nums[i]);
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i]-diff)!=s.end() && s.find(nums[i]-2*diff)!=s.end()) count++;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    vector<int> v(t);
    for(int i=0;i<t;i++) cin>>v[i];
    int n;
    cin>>n;
    cout<<"No. of Triplets: "<<arithmeticTriplets(v,n)<<endl;

    return 0;
}

/*
2367. Number of Arithmetic Triplets
@author: nmanish_0128
*/