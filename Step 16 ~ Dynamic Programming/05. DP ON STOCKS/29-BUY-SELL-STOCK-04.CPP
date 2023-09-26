#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// exact similar to Buy and Sell Stock 3 (just there was limit = 2 and here limit = k)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return memo(prices, n, 0, 1, k, dp) ;
    }
    int memo (vector<int>&price, int n, int ind, int buy, int tx, vector<vector<vector<int>>>&dp) {
        // base condition
        if(ind==n or !tx){return 0 ;}
        if(dp[ind][buy][tx]!= -1){return dp[ind][buy][tx];}
        int profit =0 ;
        if(buy) {
            profit += max(0 + memo(price, n, ind+1, buy, tx, dp), -price[ind]+memo(price, n, ind+1, !buy, tx, dp)) ;
        }
        else{
            // we can sell
            profit += max(0 + memo(price, n, ind+1, buy, tx, dp), price[ind]+memo(price, n, ind+1, !buy, tx-1, dp)) ;
        }
        return dp[ind][buy][tx] = profit ;
    }
};