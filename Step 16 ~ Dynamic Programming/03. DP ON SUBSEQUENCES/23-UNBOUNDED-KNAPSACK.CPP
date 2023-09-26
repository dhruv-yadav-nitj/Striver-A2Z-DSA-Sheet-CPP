#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int recursion (int val[], int wt[], int N, int i,int W) {
        // base condition
        if(i == N) {return 0;}

        // either pick or not pick
        int pick (0), notPick (0) ;
        if(wt[i] <= W) {
            pick = val[i] + recursion(val, wt,N, i, W - wt[i]) ;
        }
        notPick = recursion(val, wt, N, i+1, W) ;
        return max(pick, notPick) ;
    }
    int knapSack(int N, int W, int val[], int wt[]) {
        return recursion(val, wt, N, 0, W) ;

        vector<vector<int>> dp (N, vector<int> (W+1, -1)) ;
        return memo (val, wt, N, 0, W, dp) ;
    }
    int memo (int val[],int wt[], int N, int i, int W, vector<vector<int>>&dp) {
        // base condition
        if(W ==0){return 0 ;} // this was not necessay condition -> but it can be added to reduce the recursion calls
        if(i == N) {return 0 ;}
        if(dp[i][W] != -1){return dp[i][W] ;}

        int pick(0), notPick(0) ;
        if(wt[i] <= W) {
            pick = val[i] + memo(val, wt, N, i, W-wt[i], dp) ;
        }
        notPick = 0 + memo(val, wt, N, i+1, W, dp);
        return dp[i][W] = max(pick, notPick) ;
    }
};