// link - https://leetcode.com/problems/split-a-string-in-balanced-strings/description/
// 1221. Split a String in Balanced Strings

// Input: s = "RLRRLLRLRL"
// Output: 4
// Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s) {
    int count=0;
    int l=0,r=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
        if(l==r) count++;
    }
    return count;
}

int main(){
    string s;
    cin>>s;
    cout<<"No. of Balanced Split String: "<<balancedStringSplit(s)<<endl;

    return 0;
}

/*
1221. Split a String in Balanced Strings
@author: nmanish_0128
*/