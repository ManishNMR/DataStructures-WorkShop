// link - https://leetcode.com/problems/maximum-strong-pair-xor-i/description/
// 2932. Maximum Strong Pair XOR I

// Input: nums = [1,2,3,4,5]
// Output: 7
// Explanation: There are 11 strong pairs in the array nums: (1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) and (5, 5).
// The maximum XOR possible from these pairs is 3 XOR 4 = 7.

#include <iostream>
#include <vector>
using namespace std;

int maximumStrongPairXor(vector<int>& nums) {
        int maxXOR = 0;

        for ( auto x : nums ) {
            for ( auto y : nums ) {
                if ( abs(x-y) <= min(x,y) ) { 
                    int XOR = x^y;
                    maxXOR = max( maxXOR, XOR );
                }
            }
        }
        return maxXOR;
    }

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Max Strong Pair Xor: " << maximumStrongPairXor(v)<<endl;

    return 0;
}

/*
2932. Maximum Strong Pair XOR I
@author: nmanish_0128
*/