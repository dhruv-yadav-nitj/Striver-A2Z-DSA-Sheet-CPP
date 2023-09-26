#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change/

// GREEDY CODE (if someone thought)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(), coins.end(), greater()) ;
        int i = 0 ; int n = coins.size() ;
        int cnt(0);
        while(i < n and amount > 0) {
            if(coins[i] <= amount) {
                cnt++ ; amount = amount - coins[i] ;
            }
            else{i++ ;}
        }
        if(amount ==0){return cnt ;}else{return -1 ;}
    }
};

// Why Greedy cant be used here ? assume example to be  :- [186,419,83,408] and amount = 6249 --> according to greedy it is not possible to arrange the change but it is possible.

// DP Solution
class Solution {
public:
    int memo (vector<int>&coins, int n, int i, int amount, vector<vector<int>>&dp) {
        // base condition
        if(i == n){
            if(amount == 0){return 0 ;}
            else{
                return 1e9 ;
            }
        }
        if(coins[i] == amount){return 1 ;}

        if(dp[i][amount] != -1){return dp[i][amount] ;}

        int pick(1e9), notPick(1e9) ;
        if(coins[i] <= amount){
            pick = 1 + memo(coins, n, i, amount-coins[i], dp);
        }

        notPick = memo(coins, n, i+1, amount, dp) ;
        return dp[i][amount] = min(pick, notPick) ;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<vector<int>> dp (n, vector<int>(amount+1, -1)) ;
        int ans= memo(coins, n, 0, amount, dp) ;
        if(ans == 1e9){return -1;}
        else{
            return ans ;
        }
    }
};