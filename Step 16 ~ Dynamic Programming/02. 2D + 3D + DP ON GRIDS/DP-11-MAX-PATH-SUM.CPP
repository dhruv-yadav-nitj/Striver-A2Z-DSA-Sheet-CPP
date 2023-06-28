#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid (int n ,int i , int j) {
        return (i >=0 and j >=0 and i < n and j < n) ;
    }
    int recursion (vector<vector<int>>&grid , int n , int row, int col) {
        // base condition
        if(!isValid(n , row, col)) {
            return 0 ;
        }

        int up = recursion(grid, n , row -1 , col) , upLeft = recursion(grid, n , row-1, col-1) , upRight= recursion(grid, n , row-1, col +1);
        return grid[row][col] + max(max(up, upLeft), upRight) ;
    }
    
    int memoization (vector<vector<int>>&grid, int n , int row, int col, vector<vector<int>>&dp) {
        // base condition -> if the pointer goes out of the boundary -> return 0 so such the path ends and it does not even count this cell
        if(!isValid(n , row, col)) {
            return 0 ;
        }

        if(dp[row][col] != -1){
            return dp[row][col] ;
        }

        int up = memoization(grid, n, row-1, col, dp) , left = memoization(grid, n , row-1, col-1, dp) , right = memoization(grid, n , row-1, col +1, dp) ;
        return dp[row][col] = grid[row][col] + max(max(up, left) , right) ;

    }

    int maximumPath(int N, vector<vector<int>> Matrix) {
        // code here
        int ans= INT_MIN ; vector<vector<int>> dp(N , vector<int>(N, -1)) ;
        for(int col = 0 ; col < N ; col++){
            ans= max(ans , memoization(Matrix, N , N-1, col, dp)) ;
        }

        return ans ;
    }
};