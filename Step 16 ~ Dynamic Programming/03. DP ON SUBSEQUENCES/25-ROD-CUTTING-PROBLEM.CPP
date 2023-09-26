#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// Approach
/* when we cut stick -> it would be divided into two parts -> here we are recursively exploring all the possible options to make a cut and isolate left part of the stick and then explore all the possible cuts to make on the right path by senting it further into recursion */

class Solution {
public:
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp (n, vector<int>(n+1, -1)) ;
        return memo(price, n, 0, n, dp) ;
        
    }
    int memo (int price[], int n, int i, int len, vector<vector<int>>&dp) {
        // base condition
        if(len == 0 or i >= n) {return 0 ;}
        if(dp[i][len] != -1){return dp[i][len] ;}

        int pick (0) , notPick(0) ;

        // check if its possible to cut the stick into a part of i+1 (why i+1 -> bcz of 1-based indexing -> if i = 0 -> then check for cut of length of i = 1 )
        if(i + 1 <= len) {
            pick = price[i] + memo(price, n, i, len-(i+1), dp) ;
        }

        notPick = memo(price, n, i+1, len, dp) ;
        return dp[i][len] = max(pick, notPick) ;
    }
};