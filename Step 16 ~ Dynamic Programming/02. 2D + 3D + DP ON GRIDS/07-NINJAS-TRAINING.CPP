#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?leftPanelTab=0

class Solution {
public:
    int recursion (vector<vector<int>>&points, int n, int curr, int prev) {
        // base conditions
        if(curr < 0){return 0 ;}
        int maxi = INT_MIN ;
        for(int i =0 ;i < 3 ; i++) {
            if(i != prev) {
                int t = points[curr][i] + recursion(points, n, curr-1, i) ;
                maxi = max(maxi, t) ;
            }
        }
        return maxi ;
    }
    int helper (vector<vector<int>>&points, int n) {
        vector<vector<int>> dp (n , vector<int> (4, -1))  ;
        return memoization(points, n, n-1, 3, dp) ;
    }
    int memoization (vector<vector<int>>&points, int n, int curr, int prev, vector<vector<int>>&dp) {
        // base condition
        if(curr < 0) {return 0 ;}
        if(dp[curr][prev] != -1) {return dp[curr][prev] ;}

        int maxi = INT_MIN ;
        for(int i =0 ;i < 3 ; i++) {
            if(i != prev) {
                int t = points[curr][i] + memoization(points, n, curr-1, i, dp) ;
                maxi = max(maxi, t) ;
            }
        }
        return dp[curr][prev] = maxi ;
    }
};
int ninjaTraining(int n, vector<vector<int>> &points) {
    Solution obj ;
    return obj.recursion (points, n, n-1, -1) ;
    return obj.helper(points, n) ;
}