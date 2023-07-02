#include <bits/stdc++.h>
using namespace std;

// more of a greedy problem

// gfg version (many transactions allowed)
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
// in this problem we were asked to give buy, sell pairs
// we can buy and sell as many times as we want but we cant buy or sell continuously stocks i.e, if we have bought some stock then first we need to sell it than only we can buy another stock
class Solution {
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n) {
        // code here
        vector<vector<int>> ans ;
        int b = 0 , s =0 ; bool buy = true ; // b -> index of the day when we buy a stock ; s -> index of the day when we sell a stock ; buy -> if its true then we are allowed to buy a stock else we need to sell the stock we already bought
        for(int i =0 ;i < n ; i++) {
            // increased the index until the price of stock were decreasing -> and at the very index where the price of stock started increasing -> buy it -> also for that we need to be allowed to buy the stock
            if(buy and A[i +1] > A[i]) {
                b= i ; buy = false ;
            }
            else if(!buy and A[i+1] < A[i] and A[i] > A[b]) { // increase the index until the price of stock were increasing and sell it at the very index when the price of stock started decreasing from next index -> also for that we must have already bought some stock (buy should be false)
                s = i ; ans.push_back({b, s}); buy = true ;
            }
        }

        // if the last bought stock is unsold and also we can book some profit by selling at the last day -> sell it
        if(!buy and A[n-1] > A[b]) {
            ans.push_back({b, n-1}) ;
        }
        return ans ;
    }
};

// codestudio version (atmost one transaction allowed)
// https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos
// in this problem we were asked to give the maxProfit we can make -> i.e., we can make at most 1 transaction and we need to maximise the profit
int maximumProfit(vector<int> &prices) {
    // Write your code here.
    int mini = prices[0] , cost= 0 , maxProfit =0 ;
    for(int i =1 ; i < prices.size() ; i++) {
        if(prices[i] > mini) {
            cost = prices[i] - mini ;
            maxProfit = max(maxProfit , cost) ;
        }
        mini = min(mini ,prices[i]) ; // remembering the past (remembering the minimum)
    }
    return maxProfit ;
}