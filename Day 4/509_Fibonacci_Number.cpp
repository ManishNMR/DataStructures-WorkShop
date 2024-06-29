// link - https://leetcode.com/problems/fibonacci-number/
// 509. Fibonacci Number

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

#include <iostream>
using namespace std;

// Dynamic Programming
int fib(int n) {
    int f[n+1];
    if (n == 1 || n == 0) return n;
    f[0] = 0;
    f[1] = 1; 
    for (int i=2; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    cout<<"Fibonacci Number: "<<fib(n)<<endl;

    return 0;
}

/*
509. Fibonacci Number
@author: nmanish_0128
*/