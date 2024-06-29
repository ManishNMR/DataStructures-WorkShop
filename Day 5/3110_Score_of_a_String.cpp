// link - https://leetcode.com/problems/score-of-a-string/
// 3110. Score of a String

// Input: s = "hello"
// Output: 13
// Explanation:
// The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

#include <iostream>
#include <string>
using namespace std;

// optimal solution
int scoreOfString(string s) {
    int sum = 0;
    for(int i=0;i<s.length()-1;i++){
        sum+=abs(s[i]-s[i+1]);
    }
    return sum;
}

int main(){
    string s;
    cin>>s;
    cout<<"Score of String: "<<scoreOfString(s)<<endl;
}

/*
3110. Score of a String
@author: nmanish_0128
*/