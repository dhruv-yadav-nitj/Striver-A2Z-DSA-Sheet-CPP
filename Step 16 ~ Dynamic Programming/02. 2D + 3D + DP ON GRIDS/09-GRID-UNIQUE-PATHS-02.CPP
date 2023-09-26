#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/
// Simply a follow-up problem of prev problem just add one more condition in the base condition that if u encounter a grid[i][j] = 1 or a stone in the way -> just return 0

class Solution {
public:
    int memoization (vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp) {
        if(i < 0 or j < 0 or grid[i][j]==1){return 0 ;}
        if(i ==0 and j ==0) {return 1 ;}

        if(dp[i][j] != -1){return dp[i][j] ;}

        return dp[i][j]= memoization(grid, i-1, j, dp) + memoization(grid, i, j-1, dp) ;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size() ;
        vector<vector<int>> dp (n , vector<int>(m, -1)) ;

        return memoization(obstacleGrid, n-1, m-1, dp) ;
    }
};