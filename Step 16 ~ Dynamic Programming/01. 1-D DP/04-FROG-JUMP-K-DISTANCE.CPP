#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_b

int memoization (vector<int>&arr, int n, int ind, int k, vector<int>&dp) {

    if(ind ==0){return 0;}
    if(dp[ind] !=-1){return dp[ind] ;}

    int mini (INT_MAX) ;
    for(int j = 1 ; j <=k ; j++) {
        if(ind -j >=0) {
            int jumpCost = abs(arr[ind]-arr[ind-j]) + memoization(arr, n, ind-j, k, dp) ;
            mini = min(mini, jumpCost) ;
        }
    }
    return dp[ind] = mini ;
}