// link - https://leetcode.com/problems/defanging-an-ip-address/
// 1108. Defanging an IP Address

// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"

#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address) {
    string ans;
    for(int i=0;i<address.length();i++){
        if(address[i]=='.'){
            ans.push_back('[');
            ans.push_back(address[i]);
            ans.push_back(']');
        }else{
            ans.push_back(address[i]);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<"Defarging IP: "<<defangIPaddr(s)<<endl;

    return 0;
}

/*
1108. Defanging an IP Address
@author: nmanish_0128
*/