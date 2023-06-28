#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (int price[] , int n , int index, int rem) {
        // base condition
        if(rem ==0 or index < 0) {return 0 ;}

        int pick = 0 , not_pick=0 ;
        // if we decide to pick the current length then we also need to check whether we can cut the rope into this length or not
        if(index + 1  <= rem) {
            pick = price[index] + recursion(price, n, index, rem -(index +1)) ;
        }

        // not pick
        not_pick = recursion(price, n , index -1 , rem) ;

        return max(pick, not_pick) ;
    }
    int memoization (int price[], int n, int index, int rem, vector<vector<int>>&dp) {
        // base condition
        if(rem ==0 or index <0) {
            return 0 ;
        }

        if(dp[index][rem] != -1) {
            return dp[index][rem] ;
        }

        int pick =0 , not_pick = 0 ;

        if(index +1 <= rem) {
            pick = price[index] + memoization(price, n , index, rem - (index +1) , dp) ;
        }

        not_pick = memoization(price , n , index -1 , rem , dp) ;

        return dp[index][rem] = max(pick, not_pick) ;

    }
    int cutRod(int price[], int n) {
        // code here
        return recursion(price, n , n-1, n) ;

        vector<vector<int>> dp (n , vector<int> (n +1 , -1)) ;
        return memoization(price, n, n -1 , n, dp) ;

    }
};