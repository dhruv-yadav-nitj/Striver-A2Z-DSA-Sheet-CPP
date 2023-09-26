#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size() ;
        vector<vector<int>> dp (n, vector<int>(amount+1, -1)); 
        return memo(coins, n, 0, amount, dp) ;
    }
    int memo (vector<int>&coins, int n, int i, int amount, vector<vector<int>>&dp) {
        // base condition
        if(amount ==0){return 1 ;}
        if(i == n and amount > 0) {return 0 ;}

        if(dp[i][amount] != -1){return dp[i][amount] ;}

        int pick(0) , notPick (0);
        if(coins[i] <= amount) {
            pick = memo(coins, n, i, amount - coins[i], dp) ;
        }
        notPick= memo(coins, n, i+1, amount, dp) ;
        return dp[i][amount] = pick + notPick ;
    }
};