#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cherry-pickup-ii/
/* [Medium-Hard] */

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n=grid.size(), m = grid[0].size() ;
        return recursion(grid, n,m, 0, 0, m-1) ;

        vector<vector<vector<int>>> dp (n , vector<vector<int>>(m, vector<int>(m, -1))) ;
        return memoization(grid, n, m, 0, 0, m-1, dp) ;

    }
    int recursion (vector<vector<int>>&grid, int n, int m, int i, int j1, int j2) {
        // robot1 pos : i, j1 ; robot2 pos : i, j2
        
        // base condition
        if(j1 < 0 or j1 >= m or j2 < 0 or j2 >= m){return -1e7 ;}
        if(i == n-1) {
            // both are at the same cell -> return the cherry count only once
            if(j1 == j2){return grid[i][j1] ;}
            else{return grid[i][j1] + grid[i][j2] ;}
        }

        int maxi =0 ;
        // for any pos of robot1 there are 3 other possible pos of robot2 and vice versa -> in total there can 3x3=9 possible combinations
        for (int k = -1 ; k <= 1 ; k++) {
            for(int s = -1 ; s <=1 ; s++) {
                // if they are at the same cell -> count this cherry only once
                if(j1 == j2) {
                    maxi = max(maxi, grid[i][j1] + recursion(grid, n, m, i+1, j1 + k, j2 + s)) ;
                }
                else{
                    maxi=max(maxi, grid[i][j1]+grid[i][j2]+recursion(grid, n, m, i+1, j1+k, j2+s));
                }
            }
        }
        return maxi ;
    }
    int memoization (vector<vector<int>>&grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>>&dp) {
        // robot1 pos : i, j1 ; robot2 pos : i, j2
        
        // base condition
        if(j1 < 0 or j1 >= m or j2 < 0 or j2 >= m){return -1e7 ;}
        if(i == n-1) {
            // both are at the same cell -> return the cherry count only once
            if(j1 == j2){return grid[i][j1] ;}
            else{return grid[i][j1] + grid[i][j2] ;}
        }

        if(dp[i][j1][j2] != -1){return dp[i][j1][j2] ;}

        int maxi =0 ;
        // for any pos of robot1 there are 3 other possible pos of robot2 and vice versa -> in total there can 3x3=9 possible combinations
        for (int k = -1 ; k <= 1 ; k++) {
            for(int s = -1 ; s <=1 ; s++) {
                // if they are at the same cell -> count this cherry only once
                if(j1 == j2) {
                    maxi = max(maxi, grid[i][j1] + memoization(grid, n, m, i+1, j1 + k, j2 + s, dp)) ;
                }
                else{
                    maxi=max(maxi, grid[i][j1]+grid[i][j2]+memoization(grid, n, m, i+1, j1+k, j2+s, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi ;
    }
};

/* Note */
/* Observations : both the robots would be at the same level at any time. both the robots would reach the last row of grid at the same time. reason : allowed movements are only down side directions, if going to left and right would have been allowed then they would not be at the same level at any time. */