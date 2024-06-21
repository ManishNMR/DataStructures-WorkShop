// link - https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
// Output: 3
// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int count=0;
    int i=0,j=0;
    int sum = 0;
    int tar = threshold*k;
    while(true){
        if(j-i==k-1){
            sum+=arr[j++];
            if(sum>=tar) count++;
            sum-=arr[i++];
        }else{
            sum+=arr[j++];
        }
        if(j>arr.size()-1) break;
    }
    cout<<count<<endl;
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[n];
    int k,th;
    cin>>k>>th;
    cout<<"Number Of SubArray: "<<numOfSubarrays(arr,k,th)<<endl;

    return 0;
}

/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
@author: nmanish_0128
*/