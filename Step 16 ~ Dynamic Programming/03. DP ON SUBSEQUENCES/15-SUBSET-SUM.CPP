#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size() ;
        vector<vector<int>> dp (n, vector<int>(sum+1, -1)) ;
        return memo(arr, 0, n, sum, dp) ;
    }
    bool memo (vector<int>&arr, int curr, int n, int target, vector<vector<int>>&dp) {

        // base condition
        if(curr == n){
            return target == 0 ;
        }

        if(dp[curr][target] != -1){return dp[curr][target] ;} 

        bool pick, notPick ; pick = notPick = false; 

        if(arr[curr] <= target) {
            pick = memo(arr, curr+1, n, target - arr[curr], dp) ;
        }

        notPick = memo(arr, curr+1, n, target, dp) ;
        return dp[curr][target] = pick or notPick ;
    }
};