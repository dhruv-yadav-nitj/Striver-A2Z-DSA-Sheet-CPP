#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time ~ O(pow(2, m*n))
    // Since we are calling 2 recursions at each step and no. of steps are m*n -> so this give a time of 2 ^ (m*n)
    int recursion (int n, int m , int i , int j) {
        // base condition 
        if(i ==0 and j==0) {
            return 1 ;
            // we reached -> it means yes there's a path -> return 1
        }
        if(i < 0 or j < 0) {
            return 0 ;
            // we gone out of the matrix -> no path -> return 0
        }

        // return left + up
        return recursion(n , m , i, j-1) + recursion(n , m, i-1, j) ;
    }

    // Time ~ O(m * n)
    // How does time reduce ? -> bcz using memoization now number of calls would reduce to the number of total steps because at max we can call each and every step and no. of steps are (m*n)
    int memoization (int n, int m , int i , int j, vector<vector<int>>&dp) {
        // base condition 
        if(i ==0 and j==0) {
            return 1 ;
            // we reached -> it means yes there's a path -> return 1
        }
        if(i < 0 or j < 0) {
            return 0 ;
            // we gone out of the matrix -> no path -> return 0
        }

        if (dp[i][j] != -1){
            return dp[i][j] ;
        }

        // return left + up
        return dp[i][j] = memoization(n , m , i, j-1, dp) + memoization(n , m, i-1, j, dp) ;
    }
    int NumberOfPath(int a, int b) {
        // code here

        // we can only move either Down or Right (if we take path from 0, 0 to a-1, b-1)
        // but since we follow top-down approach (we would take paths from a-1, b-1 to 0, 0) -> so in this case we can move either Up or Left

        return recursion(a, b, a-1, b-1) ;

        vector<vector<int>> dp (a, vector<int> (b, -1)) ;
        return memoization(a, b, a-1, b-1, dp);

    }
};