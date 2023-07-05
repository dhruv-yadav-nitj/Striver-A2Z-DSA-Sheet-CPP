#include <bits/stdc++.h>
using namespace std;

// more of a greedy problem

// similar to gfg version of Part 1 -> we can buy and sell stocks many times and with same rule stated in the prev problem but in this problem we have to return the total profit we can earn, in prev problem gfg version we were asked to return the buy, sell pairs

// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        long long b =0 , s= 0, maxProfit =0 ; bool buy = true ;
        for(int i =0 ; i < n ; i++) {
            
            if(buy and prices[i+1] > prices[i]) {
                b = prices[i]; buy = false ;
            }
            else if(!buy and prices[i+1] < prices[i]) {
                s = prices[i] ; maxProfit += (s-b) ;
                buy= true ;
            }
        }
        
        if(!buy) {
            s = prices[n-1] ;
            maxProfit += s-b ;
        }
        return maxProfit ;
    }
};