// link- https://leetcode.com/problems/find-the-pivot-integer/
// 2485. Find the Pivot Integer

// if left == right then print the i else print -1.
// Input: n = 8
// Output: 6
// Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

#include <iostream>
using namespace std;

// two pointer approch
int pivotInteger(int n) {
    int i=1,j=n;
    int left=0,right=0;
    while(true){
        if(i>=j) break;
        if(left<right){
            left = left + i;
            i++;
        }
        else{
            right = right + j;
            j--;
        }
    }
    if(left == right) return i;
    return -1;
}

// using prefix sum
int prefixSumPivotInteger(int n){
    int i = 1;int j = n-1;
    int sum1=0,sum2=0;
    while(i>=j){
        if(sum1>sum2) {sum2 += j;j--;}
        else {sum1 += i;i++;}
    }
    if(sum1==sum2) return i;
    return -1;
}

// optimal solution using 1ton sumatioin formula n(n+1)/2;
int optimalPivotInteger(int n) {
        int ans=-1;
        // if(n==1) return 1;
        for(int i=1;i<=n;i++)
        {
            int left = i*(i+1)/2;
            int right = (n)*(n+1)/2-((i-1)*i/2);
            if(left==right)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }

int main(){
    int n;
    cin>>n;

    cout<<"Pivot Integer: "<<pivotInteger(n)<<endl;
    cout<<"PrefixSum Sol: "<<prefixSumPivotInteger(n)<<endl;
    cout<<"Optimal Sol: "<<optimalPivotInteger(n)<<endl;

    return 0;
}

/*
2485. Find the Pivot Integer
@author: nmanish_0128
*/