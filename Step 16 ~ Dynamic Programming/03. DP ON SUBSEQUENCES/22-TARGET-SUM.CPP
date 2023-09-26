#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/target-sum/

// Approach #1 : my approach using pick not pick (here plus , minus)
class Solution {
public:
    int recursion (vector<int>&nums, int n, int i, int curr, int target) {
        // base condition
        if(i == n) {if(curr == target){return 1 ;} else{return 0 ;}}

        int plus(0), minus(0); 

        plus = recursion(nums, n, i+1, curr+nums[i], target) ;
        minus = recursion(nums, n, i+1, curr-nums[i], target) ;

        return plus + minus ;
    }
    int memo (vector<int>&nums, int n, int i, int k, int curr, int target, vector<vector<int>>&dp) {
        if(i == n){
            return (curr == target) ;
        }
        if(dp[i][curr+k] != -1){return dp[i][curr+k] ;}

        int plus = memo (nums, n, i+1,k, curr+nums[i], target, dp) ;
        int minus = memo(nums, n, i+1,k, curr-nums[i], target, dp) ;
        return dp[i][curr+k] = plus + minus ;
    }
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size() ;
        // return recursion(nums, n, 0, 0, target);
        vector<vector<int>> dp (n, vector<int>(2001, -1)) ;
        return memo(nums, n, 0,1000, 0, target, dp) ;
    }
};

/* Important Points : why 2001 -> bcz according to ques -> the total sum of all the element of the given array would be 1000 -> so if we place - in front of every element then the most negative sum we can get is -1000 -> since we dont have any way to represent -ve numbers in form if indexes -> we would add 1000 to each current sum -> so -1000 would be represented as 0th index in dp array and 1000 would be 2000th index in the dp array -> hence size of dp array required would be 2001 */

// Approach #2 : as a follow up problem of prev problem
// .... to be continued