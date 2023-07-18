#include <bits/stdc++.h>
using namespace std;

// brute force approach
class Solution {
public:
    long long maxSubarraySum(int arr[], int n) {
        // Your code here
        int ans = INT_MIN ;
        for(int i =0 ; i < n ; i++) {
            int temp(0);
            for(int j=i ; j < n ; j++) {
                temp = temp + arr[j] ; ans = max(ans, temp) ;
            }
        }
        return ans ;

    }
};

// optimised approach
// kadane's algorithm
class Solution {
public:
    long long maxSubarraySum(int arr[], int n) {
        // Your code here
        long long maxi =INT_MIN , sum  =0 ;
        for(int i =0 ;i < n ; i++) {
            sum += arr[i] ;
            maxi=max(maxi, sum) ;
            if(sum < 0) {
                sum =0 ;
            }
        }
        return maxi ;
    }
};