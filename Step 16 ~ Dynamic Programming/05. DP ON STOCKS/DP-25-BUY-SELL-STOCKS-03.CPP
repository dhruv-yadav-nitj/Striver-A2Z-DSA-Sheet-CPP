#include <bits/stdc++.h>
using namespace std;

// DP Approach

int recursion (vector<int>&price, int index, bool buy, int cap) {
    // base condition 
    if(index == price.size() or cap == 0) {
        return 0 ;
    }

    if(buy) {
        // if we can buy, we have 2 choices -> we can buy this stock or we would not
        // if we buy this stock then net profit at this step would be (-ve)price[index]
        int pick = -price[index] + recursion(price, index +1, !buy, cap) ; // since we bought -> change the status of buy
        
        // else we would not buy
        int not_pick = recursion(price, index +1, buy , cap) ;

        return max(pick , not_pick) ;
    }
    else{
        // we cant buy but sell
        // then again we have 2 choices -> we can pick to sell or not pick to sell
        int pick = price[index] + recursion(price, index +1, !buy, cap -1) ; // since we sold -> change the status of buy
        // if we choose to sell -> then we our net profit would be (+ve)price[index] <- since we are selling and we would get money

        int not_pick = recursion(price, index +1, buy , cap) ;

        return max(pick, not_pick) ;
    }
}

int memoization (vector<int>&price, int index, bool buy , int cap, vector<vector<vector<int>>>&dp) {

    // base condition
    if(index == price.size() or cap == 0) {
        return 0 ;
    }

    if(dp[index][buy][cap] != -1) {return dp[index][buy][cap] ;}

    if(buy) {
        // if we can buy, we have 2 choices -> we can buy this stock or we would not
        // if we buy this stock then net profit at this step would be (-ve)price[index]
        int pick = -price[index] + memoization(price, index +1, !buy, cap, dp) ; // since we bought -> change the status of buy
        
        // else we would not buy
        int not_pick = memoization(price, index +1, buy , cap, dp) ;

        return dp[index][buy][cap] = max(pick , not_pick) ;
    }
    else{
        // we cant buy but sell
        // then again we have 2 choices -> we can pick to sell or not pick to sell
        int pick = price[index] + memoization(price, index +1, !buy, cap -1, dp) ; // since we sold -> change the status of buy
        // if we choose to sell -> then we our net profit would be (+ve)price[index] <- since we are selling and we would get money

        int not_pick = memoization(price, index +1, buy , cap, dp) ;

        return dp[index][buy][cap] = max(pick, not_pick) ;
    }

}

int maxProfit(vector<int> &price) {
    // Write your code here..
    return recursion(price, 0 , true, 2) ;
    int n = price.size() ;
    vector<vector<vector<int>>> dp (n , vector<vector<int>> (2, vector<int>(3, -1))) ;

    return memoization(price, 0 , true, 2, dp) ;
    
}