// link - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
// 2108. Find First Palindromic String in the Array

// Input: words = ["abc","car","ada","racecar","cool"]
// Output: "ada"
// Explanation: The first string that is palindromic is "ada".
// Note that "racecar" is also palindromic, but it is not the first.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// two pointer approch
string firstPalindrome(vector<string>& words) {
    int i=0;
    while(i<words.size()){
        int left = 0;
        int right = words[i].length()-1;
        bool flag = true;
        while(left<=right){
            if(words[i][left]!=words[i][right]){
                flag = false;
                break;
            }
            left++;
            right--;
        }
        if(flag) return words[i];
        i++;
    }
    return "";
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<firstPalindrome(v)<<endl;;

    return 0;
}

/*
2108. Find First Palindromic String in the Array
@author: nmanish_0128
*/