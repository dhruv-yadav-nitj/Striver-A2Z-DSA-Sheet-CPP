#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
/* we have find the all possible subsequence sum we can have -> so at last we would find the min difference we can have */

class Solution {
public:
    bool memo (vector<int>&nums, int n,int curr, int target, vector<vector<int>>&dp) {

        // base condition
        if(curr == n){
            return target == 0 ;
        }

        if(dp[curr][target] != -1){return dp[curr][target] ;} 

        bool pick, notPick ; pick = notPick = false; 

        if(nums[curr] <= target) {
            pick = memo(nums, curr+1, n, target - nums[curr], dp) ;
        }

        notPick = memo(nums, curr+1, n, target, dp) ;
        return dp[curr][target] = pick or notPick ;
    }
    int minimumDifference(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end() , 0) ;
        int n = nums.size() ;
        vector<vector<int>> dp (n, vector<int>(sum+1, -1)) ;

        for(int i =0 ; i <= sum ; i++) {
            memo(nums, n, 0, i, dp) ;
        }

        int mini = INT_MAX ;
        for(int i =0 ; i <= sum ; i++) {
            if(dp[n-1][i]){
                int diff = abs(i - (sum - i)) ;
                mini = min(mini, diff) ;
            }
        }
        return mini ;
    }
};