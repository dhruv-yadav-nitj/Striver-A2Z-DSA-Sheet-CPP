#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/frog-jump_3621012

class Solution {
public :
    
    int recursion (int curr, vector<int>&heights) {

        if(curr == 0) {return 0;} // base condition
        // it signifies there is no further energy needed

        int step1 (INT_MAX) , step2(INT_MAX) ;

        // ek step to kabhi bhi le skte hain
        step1 = abs(heights[curr]-heights[curr-1])+recursion(curr-1, heights);

        if(curr > 1){
            // but do step down tbhi aa skte hain jb curr >= 2
            step2 = abs(heights[curr]-heights[curr-2]) + recursion(curr-2, heights);
        }

        return min(step1, step2) ;
    }

    int memoization (int curr, vector<int>&heights, vector<int>&dp){

        if(curr == 0){return 0 ;}

        if(dp[curr] != -1){return dp[curr];}

        int step1 = INT_MAX, step2= INT_MAX ;
        step1 = abs(heights[curr]-heights[curr-1]) + memoization(curr-1, heights, dp) ;
        if(curr >= 2){
            step2 = abs(heights[curr]-heights[curr-2]) + memoization(curr-2, heights, dp);
        }

        return dp[curr] = min(step1, step2) ;
    }

    int tabulation (vector<int>&heights, int n) {
        vector<int> dp (n, -1) ;
        dp[0] = 0 ; dp[1] = abs(heights[1]-heights[0]);
        for(int i =2 ;i < n ; i++) {
            dp[i] = min( (abs(heights[i]-heights[i-1]) + dp[i-1]), (abs(heights[i]-heights[i-2]) + dp[i-2]) ) ;
        }
        return dp[n-1] ;
    }

};

int frogJump(int n, vector<int> &heights) {

    Solution obj ;
    return obj.recursion(n-1, heights) ;
    vector<int> dp (n, -1) ;
    return obj.memoization(n-1, heights, dp) ;
    return obj.tabulation(heights, n);
}