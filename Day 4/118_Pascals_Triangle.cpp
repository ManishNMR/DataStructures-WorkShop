// link - https://leetcode.com/problems/pascals-triangle/
// 118. Pascal's Triangle

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++){
        vector<int> curr(i+1,1);
        for(int j=1;j<i;j++){
            curr[j]=ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(curr);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    cout<<"Generated Optimal: ";
    vector<vector<int>> v = generate(t);
    for(auto it: v) { cout<<"{";for(auto i: it) cout<<i<<" "; cout<<"} ";}
    cout<<endl;
}

/*
118. Pascal's Triangle
@author: nmanish_0128
*/