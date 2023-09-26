#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/triangle/
// just a follow up ques of the prev problem -> in this problem we have to just see that what would be the vertical indices we can fall to when we moving from one level up to down and that would be j and j +1 (draw a matrix for the given example and u would understand)

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {

        return recursion(triangle, triangle.size(), 0, 0) ;
        int n = triangle.size() ; int m = triangle[n-1].size() ;
        vector<vector<int>> dp (n, vector<int>(m, -1)) ;
        return memoization(triangle, n, 0, 0, dp) ;

    }
    int recursion (vector<vector<int>>&tri,int n, int i, int j) {

        // base condition -> we reached at the lower most level
        if(i==n-1){return tri[i][j] ;}
        if(j > tri[i].size()){return 1e7 ;} // if we went out of bound

        int left, right ; left=right=tri[i][j] ;
        left += recursion(tri, n, i+1, j) ;
        right += recursion(tri, n, i+1, j+1) ;

        return min(left, right) ;
        
    }
    int memoization (vector<vector<int>>&tri,int n, int i, int j, vector<vector<int>>&dp){

        // base condition -> we reached at the lower most level
        if(i==n-1){return tri[i][j] ;}
        if(j > tri[i].size()){return 1e7 ;} // if we went out of bound

        if(dp[i][j] != -1){return dp[i][j] ;}

        int left, right ; left=right=tri[i][j] ;
        left += memoization(tri, n, i+1, j, dp) ;
        right += memoization(tri, n, i+1, j+1, dp) ;

        return dp[i][j] = min(left, right) ;

    }
};