#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-falling-path-sum/
// similar to previous problem only
class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size() ;
        
        /* 
        int ans = 1e7 ;
        vector<vector<int>> dp (n, vector<int>(m, -1)) ;
        // since we can start from any point at the first level
        for(int i =0; i < m ; i++) {
            ans = min(ans, memoization (matrix, n, m, 0, i, dp)) ;
        }
        return ans ;
        */
       
        /* Tabulation Method */
        vector<vector<int>> dpp (n , vector<int>(m, 0)) ;
        // store the ans for first row
        for(int j =0 ; j < m ; j++) {
            dpp[0][j] = matrix[0][j] ;
        }

        for(int i =1 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int up , left, right ;
                up = left = right = matrix[i][j] ;
                
                up += dpp[i-1][j] ;
                if(j - 1 >=0 ){
                    left += dpp[i-1][j-1] ;
                } else{left = 1e7 ;}
                if(j + 1 < m){
                    right += dpp[i-1][j+1];
                } else{right = 1e7 ;}
                dpp [i][j] = min({up, left, right}) ;
            }
        }
        int ans (INT_MAX) ;
        for(int j =0 ;j < m ; j++) {
            ans = min(ans, dpp[n-1][j]) ;
        }
        return ans ;
    }
    int recursion (vector<vector<int>>&grid,int n,int m,int i,int j) {
        // base condition
        if(i < 0 or j < 0 or i >= n or j >= m){return 1e7 ;} // went out of bound
        if(i == n-1){return grid[i][j] ;} // reached the last level

        int l, d, r ; // left , down, right ;
        l = d = r = grid[i][j] ;

        l += recursion(grid, n,m, i+1, j-1) ;
        d += recursion(grid, n,m, i+1, j) ;
        r += recursion(grid, n,m, i+1, j+1) ;

        return min({l, d, r}) ;
    }
    int memoization (vector<vector<int>>&grid, int n,int m,int i , int j, vector<vector<int>>&dp) {

        // base condition
        if(i < 0 or j < 0 or i >= n or j >= m){return 1e7 ;} // went out of bound
        if(i == n-1){return grid[i][j] ;} // reached the last level

        if(dp[i][j] != -1){return dp[i][j] ;}

        int l, d, r ; // left , down, right ;
        l = d = r = grid[i][j] ;

        l += memoization(grid, n,m, i+1, j-1, dp) ;
        d += memoization(grid, n,m, i+1, j, dp) ;
        r += memoization(grid, n,m, i+1, j+1, dp) ;

        return dp[i][j] = min({l, d, r}) ;
    }
};