#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// we can buy and sell only one stock -> so very easy -> chose the min of all the stock and sell it in some future day (take the max of the ans)
// Approach 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,n, res, sell; n= prices.size(); res=0; sell=prices[n-1],i=n-1 ;
        // initially assuming we would sell the stock at the last day
        while(i >=0) {
            // if we assume we bought the stock at ith day and sold it at price 'sell'
            res = max(res, (sell - prices[i])) ;
            sell = max(sell, prices[i]) ;
            i-- ;
        }
        return res ;
    }
};
// Approach 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(prices[0]), ans (0) ;
        for(int i=0; i < prices.size() ; i++) {
            ans = max(ans, prices[i]-buy) ; buy = min(buy, prices[i]) ;
        }
        return ans ;
    }
};