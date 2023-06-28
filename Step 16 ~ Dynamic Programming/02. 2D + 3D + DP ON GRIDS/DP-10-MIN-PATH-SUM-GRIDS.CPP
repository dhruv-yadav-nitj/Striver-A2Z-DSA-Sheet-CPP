#include <bits/stdc++.h>
using namespace std;

// Approach #1 : using simple Djikstra'a Algorithm
class Solution {
public:
    // Function to return the minimum cost to react at bottom right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid) {
        // Code here

        int n = grid.size() ; // square matrix
        vector<vector<int>> distance (n , vector<int> (n,1e9)) ;

        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> > pq ;

        pq.push({grid[0][0] , {0, 0}}) ; distance[0][0] =grid[0][0] ;

        int row_changes[] = {-1, 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;

        while(!pq.empty()) {
            auto it = pq.top() ; pq.pop() ;
            int cost = it.first, i = it.second.first , j = it.second.second ;

            for(int k =0; k < 4 ; k++) {
                int row = i + row_changes[k] , col = j + col_changes[k] ;
                if(row >= 0 and row < n and col >= 0 and col < n) {
                    if(cost + grid[row][col] < distance[row][col]) {
                        distance[row][col]= cost + grid[row][col] ;
                        pq.push({distance[row][col] , {row , col}}) ;
                    }
                }
            }
        }

        return distance[n-1][n-1] ;

    }
};

// Approach #2 : TUTORIAL/DP APPROACH
class Solution {
public:
    int recursion (vector<vector<int>>&grid, int n, int i, int j) {
        // base condition
        if(i < 0 or j < 0 or i > n or j > n){
            return INT_MAX ;
        }
        if(i ==0 and j ==0) {
            return grid[i][j] ;
        }

        int mini = INT_MAX ;
        // move up or left (since we are moving from last cell to first cell that's the only moves we can go with for reaching 0,0)
        mini = min(recursion(grid, n , i-1 , j) , recursion(grid, n , i, j-1)) ;
        return mini + grid[i][j] ;
    }

    int memoization (vector<vector<int>>&grid, int n , int i , int j, vector<vector<int>>&dp) {
        // base condition
        if(i ==0 and j ==0) {
            return grid[i][j] ;
        }
        if(i < 0 or j < 0) {
            return INT_MAX ;
        }
        if(dp[i][j] != -1) {
            return dp[i][j] ;
        }

        return dp[i][j]= min(grid[i][j] + memoization(grid, n , i-1 , j, dp) , grid[i][j] + memoization(grid, n , i , j-1, dp)) ;

    }
    
    int minimumCostPath(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size() ; // square matrix
        return recursion(grid, n , n-1 , n-1) ;

        vector<vector<int>> dp (n , vector<int> (n , -1)) ;
        return memoization(grid, n , n-1, n-1, dp) ;
    }
};
// DP Solution at GfG was giving Error -> dont know why ?

// CodeStudio Version
// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std ;

int recursion (vector<vector<int>>&grid, int i, int j) {
    // base condition
    if(i < 0 or j < 0){
        return INT_MAX ;
    }
    if(i ==0 and j ==0) {
        return grid[i][j] ;
    }
    int mini = INT_MAX ;
    // move up or left (since we are moving from last cell to first cell that's the only moves we can go with for reaching 0,0)
    mini = min(recursion(grid,i-1 , j) , recursion(grid,i, j-1)) ;
    return mini + grid[i][j] ;
}

int memoization (vector<vector<int>>&grid, int i , int j , vector<vector<int>>&dp) {

    // base condition
    if(i ==0 and j ==0) {
        return grid[i][j] ;
    }
    // if the pointer goes out of the boundary of the matrix -> then return some large number such that this path NULLIFIES
    if(i < 0 or j < 0) { // since we can move in only two directions (up and down) -> so these are the possibilities
        return INT_MAX ;
    }

    if(dp[i][j] != -1) {
        return dp[i][j] ;
    }

    // move in upward and left direction and check the min cost path
    int mini = min(memoization(grid, i-1, j , dp) , memoization(grid, i, j-1, dp)) ;
    
    return dp[i][j] = grid[i][j] + mini ;    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size() , m = grid[0].size() ;
    return recursion (grid, n-1, m-1) ;

    vector<vector<int>> dp(n , vector<int> (m ,-1)) ;
    return memoization(grid, n-1, m-1, dp) ;
}