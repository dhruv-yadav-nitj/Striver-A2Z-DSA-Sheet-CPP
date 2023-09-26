#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// in this problem we can buy and sell stock any number of times -> but we would be holding only one stock at a time
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        bool buy = true ; int profit(0), i(0), n(prices.size()) ;
        int b, s ;
        while(i < n) {
            // skip the days where price is increasing if we want to buy
            if(buy) {
                while(i < n-1 and prices[i] > prices[i+1]) {
                    i++ ;
                }
                if(i <= n-1){b = prices[i] ; buy = false;}
            }
            else{
                // skip the days where price is decreasing if we want to sell
                while(i < n-1 and prices[i] < prices[i+1]){
                    i++ ;
                }
                if(i <= n-1){s= prices[i] ; profit += s-b ; buy= true ;}
            }
            i++ ;
        }
        if(!buy) {
            profit += prices[n-1]-b ;
        }
        return profit ;
    }
};