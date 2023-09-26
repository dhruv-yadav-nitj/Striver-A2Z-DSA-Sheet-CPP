#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
public:
    int memo (int wt[], int val[], int W, int n, int i, vector<vector<int>>&dp) {
        // base condition
        if(W ==0){return 0 ;}
        if(i ==n-1) {
            if(wt[i] <= W) {
                return val[i] ;
            }
            else{
                return 0 ;
            }
        }

        if(dp[i][W] != -1){return dp[i][W] ;}
        int pick(0), notPick (0) ;
        if(wt[i] <= W) {
            pick += val[i] + memo(wt, val, W-wt[i], n, i+1, dp) ;
        }
        notPick = memo(wt, val, W, n, i+1, dp) ;
        return dp[i][W] = max(pick, notPick) ;
    }
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp (n , vector<int>(W+1, -1)) ;
        return memo(wt, val, W, n, 0, dp) ;
    }
};