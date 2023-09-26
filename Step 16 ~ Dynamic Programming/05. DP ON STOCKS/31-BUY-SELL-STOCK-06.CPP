#include <bits/stdc++.h>
#define ll long long
using namespace std;

// BUY SELL STOCK WITH TRANSACTION FEE INCLUDED
// similar to prev problems

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ; vector<vector<int>> dp(n, vector<int>(2, -1)) ;
        return memo(prices, n, 0, 1, dp, fee) ;
    }
    int memo (vector<int>&price, int n, int ind, int buy, vector<vector<int>>&dp, int fee) {
        // base condition
        if(ind >= n) {return 0;}

        if(dp[ind][buy] != -1) {return dp[ind][buy];}

        int profit=0;
        if(buy) {
            // if we can buy -> then we can either skip this day or purchase a stock on this day
            profit += max(0+memo(price, n, ind+1, buy, dp, fee), -price[ind]+memo(price, n, ind+1,!buy, dp, fee)) ;
        }
        else{
            // if we can sell then -> we can either skip or sell on this day
            profit += max(0+memo(price, n, ind+1, buy, dp, fee), price[ind]-fee+memo(price, n, ind+1, !buy, dp, fee)) ;
        }
        return dp[ind][buy] = profit ;
    }
};