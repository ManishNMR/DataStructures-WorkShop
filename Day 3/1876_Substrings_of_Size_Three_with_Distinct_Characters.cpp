// link - https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/
// 1876. Substrings of Size Three with Distinct Characters

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
// The only good substring of length 3 is "xyz".

#include <iostream>
#include <string>
using namespace std;

// optimal solution
int countGoodSubstrings(string s) {
        int count=0;
        if(s.length()<=2) return count;
        for(int i=0;i<s.length()-2;i++){
            if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2]) count++;
        }
        return count;
    }

int main(){
    string s;
    cin>>s;
    cout<<"Number Of Good SubString: "<<countGoodSubstrings(s)<<endl;

    return 0;
}

/*
1876. Substrings of Size Three with Distinct Characters
@author: nmanish_0128
*/