#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// in this problem we are allowed to make atmost two transactions and we can hold only one stock at a time
// most important problem of BUY-SELL-STOCK TYPE PROBLEMS

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return recursion(prices, prices.size(), 0, true, 2) ;

        // ind, bool, cap
        int n = prices.size();
        vector<vector<vector<int>>> dp (n,vector<vector<int>>(2, vector<int>(3, -1))) ;

        return memo(prices, n, 0, 1, 2, dp) ;
    }
    int recursion (vector<int>&prices,int n, int ind, bool buy, int cap) {
        // base condition
        if(ind == n or !cap) {
            return 0;
        }

        int profit(0) ;
        // if we can buy -> then we can buy or not buy
        if(buy) {
            profit += max(0+recursion(prices, n, ind+1, buy, cap), (-prices[ind])+recursion(prices, n, ind+1, !buy, cap)) ;
        }
        else{
            // we can only sell -> so we can either sell or not sell
            profit += max(0+recursion(prices, n, ind+1, buy, cap), prices[ind]+recursion(prices, n, ind+1, !buy, cap-1)) ;
        }
        return profit ;
    }
    int memo (vector<int>&prices,int n, int ind, int buy, int cap, vector<vector<vector<int>>>&dp) {
        // base condition
        if(ind == n or !cap) {return 0;}
        if(dp[ind][buy][cap] != -1){return dp[ind][buy][cap];}

        int profit = 0 ;
        if(buy) {
            profit += max(0 + memo(prices, n, ind+1,buy, cap, dp), -prices[ind]+memo(prices, n, ind+1, !buy, cap, dp)) ;
        }
        else{
            profit += max(0 + memo(prices, n, ind+1, buy, cap, dp) , prices[ind]+memo(prices, n, ind+1, !buy, cap-1, dp)) ;
        }
        return dp[ind][buy][cap] = profit ;
    }
};