#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int recursion (vector<vector<int>>&grid,int i,int j){
        // base condition
        if(i < 0 or j < 0){return INT_MAX ;}
        if(i==0 and j ==0){return grid[i][j] ;}

        int up(grid[i][j]) , left(grid[i][j]) ;
        up += recursion(grid, i-1, j) ; left += recursion(grid, i, j-1) ;
        return min(up, left) ;
    }
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size() , m = grid[0].size() ;
        // return recursion(grid, n-1, m-1) ;

        vector<vector<int>> dp (n, vector<int>(m, -1)) ;
        return memoization(grid, n-1, m-1, dp) ;
    }
    int memoization (vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp) {
        // base condition
        if(i < 0 or j <0){return 0 ;}
        if(i==0 and j ==0){return grid[i][j] ;}

        if(dp[i][j] != -1){return dp[i][j] ;}
        int up , left; 
        up = left = grid[i][j] ;
        up += memoization(grid, i-1, j, dp) ;
        left += memoization(grid, i, j-1, dp) ;
        return dp[i][j] = min(up, left) ;
    }
};