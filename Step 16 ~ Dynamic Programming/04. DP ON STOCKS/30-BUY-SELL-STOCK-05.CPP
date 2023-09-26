#include <bits/stdc++.h>
#define ll long long
using namespace std;

// BUY-SELL-STOCK-WITH-COOLDOWN-ONE-DAY

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/ 

// very much similar to prev problems -> just skip a day when you sell -> also there's no limit on transactions so dp would change from 3D to 2D vector -> since nothing depends on remaining transactions, and ans depends on index and on status of buy and sell

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; vector<vector<int>> dp(n, vector<int>(2, -1)) ;
        return memo(prices, n, 0, 1, dp) ;
    }
    int memo (vector<int>&price, int n, int ind, int buy, vector<vector<int>>&dp) {
        // base condition
        if(ind >= n) {return 0;}

        if(dp[ind][buy] != -1) {return dp[ind][buy];}

        int profit=0;
        if(buy) {
            // if we can buy -> then we can either skip this day or purchase a stock on this day
            profit += max(0+memo(price, n, ind+1, buy, dp), -price[ind]+memo(price, n, ind+1,!buy, dp)) ;
        }
        else{
            // if we can sell then -> we can either skip or sell on this day
            profit += max(0+memo(price, n, ind+1, buy, dp), price[ind]+memo(price, n, ind+2, !buy, dp)) ;
        }
        return dp[ind][buy] = profit ;
    }
};