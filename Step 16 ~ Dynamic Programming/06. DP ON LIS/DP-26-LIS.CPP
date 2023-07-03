#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (int arr[], int n, int index, int prev) {
        // base condition
        if(index == n) {
            return 0 ;
        }

        // at any index we have two choices either pick or not pick (but we can only pick the curr element if its greater than prev)
        int pick=0, not_pick = 0 ;
        if(arr[index] > prev) {
            pick = 1 + recursion(arr, n, index +1, arr[index]) ;
        }
        not_pick = recursion(arr, n, index+1, prev) ;

        return max(pick, not_pick) ;
             
    }

    int memoization (int arr[], int n, int index, int prev , vector<vector<int>>&dp) {
        // base condition
        if(index == n) {
            return 0 ;
        }

        if(dp[index][prev +1] != -1) {
            return dp[index][prev +1] ;
        }

        int pick = 0, not_pick =0 ;
        if(prev == -1 or arr[index] > arr[prev]) {
            pick = 1 + memoization(arr, n , index +1, index, dp) ;
        }

        not_pick = memoization(arr, n , index +1, prev, dp) ;

        return dp[index][prev+1] = max(pick, not_pick) ;

    }

    int longestSubsequence(int n, int a[]) {
        // your code here
        return recursion(a, n , 0, -1) ;

        // easy to memoize
        vector<vector<int>> dp(n , vector<int> (n +1, -1)) ; // we need to represent the prev index in terms of 1-based indexing for obvious reasons
        return memoization(a, n, 0, -1, dp) ;

    }
};

// tabulation approach
class Solution {
public:
    int longestSubsequence(int n, int a[]) {
        // your code here

        vector<vector<int>> dp(n+1, vector<int> (n+1 , 0)) ;
        for(int i =n-1 ; i >= 0; i--) {
            for(int j = i -1 ; j >=-1 ; j--) {
                int take =0 , notTake = 0 ;
                
                // take
                if(j == -1 or a[i] > a[j]) {
                    take = 1 + dp[i +1][i+1] ;
                }
                notTake = dp[i+1][j +1] ;

                dp[i][j+1] =max(take, notTake) ;
            }
        }

        return dp[0][0] ;

    }
};