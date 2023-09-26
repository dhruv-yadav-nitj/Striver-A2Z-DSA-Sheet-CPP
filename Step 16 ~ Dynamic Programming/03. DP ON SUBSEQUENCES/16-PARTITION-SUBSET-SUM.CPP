#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/description/
/* 
In this problem, we need to divide the total array into two arrays with equal sum -> means each new array would be having sum = totalSum / 2 -> which means we need to find a subsequence with target sum = totalSum /2
*/

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int target = accumulate(nums.begin(), nums.end() , 0) ;
        if((target&1)){return false ;} // if the total Sum is odd -> then we cant divide the array into two parts with equal sum
        int n=nums.size() , k = target/2 ;
        vector<vector<int>> dp (n , vector<int>(k+1, -1)) ;
        return memo(nums, n, 0, 0, k, dp) ;

    }
    bool memo (vector<int>&arr, int n, int ind, int sum, int target, vector<vector<int>>&dp){
        // base condition
        if(ind == n){
            return sum==target ;
        }
        if(dp[ind][sum] != -1){return dp[ind][sum] ;}
        bool pick(false) , notPick(false) ;
        // pick
        if(arr[ind] <= target - sum){
            pick = memo(arr, n, ind+1, sum+arr[ind], target, dp) ;
        }

        // not-pick
        notPick = memo(arr, n, ind+1, sum, target, dp) ;

        return dp[ind][sum] = pick or notPick ;
    }
};