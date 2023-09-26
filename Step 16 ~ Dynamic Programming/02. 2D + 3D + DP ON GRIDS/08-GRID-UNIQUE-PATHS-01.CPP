#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (int i, int j){
        // base condition 
        if(i < 0 or j < 0){return 0 ;}
        if(i==0 and j ==0){return 1 ;}

        // at any point we can either take up or left path
        int up(0), left(0) ;

        return recursion(i -1, j) + recursion(i , j-1) ;        
    }
    int uniquePaths(int m, int n) {

        return recursion(m-1, n-1) ;

        vector<vector<int>>dp (m , vector<int>(n, -1)) ;
        return memoization(m-1, n-1, dp) ;
    }

    int memoization (int i , int j , vector<vector<int>>&dp) {

        // base condition
        if(i < 0 or j < 0){return 0 ;}
        if(i==0 and j==0){return 1 ;}

        if(dp[i][j] != -1){return dp[i][j] ;}

        return dp[i][j] = memoization(i-1, j, dp) + memoization(i, j-1, dp) ;
    }
};