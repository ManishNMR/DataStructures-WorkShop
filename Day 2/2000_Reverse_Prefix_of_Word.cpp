// link - https://leetcode.com/problems/reverse-prefix-of-word/description/
// 2000. Reverse Prefix of Word

// Input: word = "xyxzxe", ch = "z"
// Output: "zxyxxe"
// Explanation: The first and only occurrence of "z" is at index 3.
// Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// two pointer approch
string reversePrefix(string word, char ch) {
    int left = 0;
    int right = 0;
    bool flag = false;
    while(left<word.length()){
        if(word[left]==ch){
            right = left;
            flag = true;
            break;
        }
        left++;
    }

    if(!flag) return word;
    left = 0;
    while(left<right){
        swap(word[left],word[right]);
        left++;
        right--;
    }
    return word;
}

// Optimal solution
string optimalReversePrefix(string word, char ch) {
    for(int i=0;i<word.length();i++){
        if(word[i]==ch){
            reverse(word.begin(),word.begin()+i+1);
            break;
        }
    }
    return word;
}

int main(){
    string s;
    char ch;
    cin>>s>>ch;
    cout<<"Reverse Prefix: "<<reversePrefix(s,ch)<<endl;
    cout<<"Optimal Reverse Prefix: "<<optimalReversePrefix(s,ch)<<endl;
    
    return 0;
}

/*
2000. Reverse Prefix of Word
@author: nmanish_0128
*/