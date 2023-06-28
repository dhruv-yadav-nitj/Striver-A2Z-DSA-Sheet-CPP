#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (int wt[] , int val[], int n, int index, int rem) {
        // base condition
        if(rem ==0) {
            return 0 ;
        }
        if(index ==0) {
            if(wt[index] <= rem) {
                return val[index] ;
            }
            else{
                return 0 ;
            }
        }

        int pick =0, not_pick=0 ;
        // at any index we can either pick or not pick

        if(wt[index] <= rem) {
            pick = val[index] + recursion(wt, val , n , index -1 , rem - wt[index]) ;
        }

        // not pick
        not_pick = recursion(wt, val , n , index -1, rem) ;

        return max(pick , not_pick) ;

    }

    int memoization (int wt[], int val[], int index, int rem, vector<vector<int>>&dp){
        // base condition
        if(rem ==0) {
            return 0 ;
        }
        if(index ==0) {
            if(wt[index] <= rem) {
                return val[index] ;
            }
            else{
                return 0 ;
            }
        }

        if(dp[index][rem] != -1) {
            return dp[index][rem] ;
        }

        int pick = 0 , not_pick =0 ;
        // pick only when current knapsack has weight less than or equal to remaining capacity
        if(wt[index] <= rem) {
            pick = val[index] + memoization(wt, val, index -1, rem - wt[index] , dp) ;
        }

        not_pick = memoization(wt, val, index -1, rem, dp) ;

        return dp[index][rem] = max(pick, not_pick) ;
    }

    int knapSack(int W, int wt[], int val[], int n) {
        // Your code here
        return recursion(wt, val, n , n-1, W) ;

        vector<vector<int>> dp(n , vector<int> (W +1, -1)) ;
        return memoization(wt, val, n-1, W, dp) ;
    }
};