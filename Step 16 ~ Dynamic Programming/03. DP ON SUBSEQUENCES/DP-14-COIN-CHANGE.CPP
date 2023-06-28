#include <bits/stdc++.h>
using namespace std;

// Pre-requisite : Combination Sum I

class Solution {
public:
    long long recursion(int coins[], int n, int index, int target) {
        // base condition -> if the current index is 0 -> means we reached the end -> so the current element can satisfy the target then return 1 (means yes its a combination) else return 0 (nullify the current combination)

        if(target ==0) {
            return 1 ;
        }
        if(index < 0){
            return 0 ;
        }

        int pick = 0, not_pick = 0 ; // at any index we can either pick or not pick the element -> so initially number of ways take 0 then we will add

        if(coins[index] <= target) {
            pick = recursion(coins, n, index , target - coins[index]) ; // since we can choose one coin any number of time so index would not change
        }

        not_pick= recursion(coins, n, index -1, target) ; // if we choose to not pick the current element then decrease the index and no effect on target

        return pick + not_pick ;

    }

    long long memoization(int coins[], int n, int index, int target, vector<vector<int>>&dp) {
        // base conditions -> if target is now 0 -> which means we need to return 1 (means there's a way) -> but if the index becomes less than 0 which means there's no way -> return 0

        if(target ==0) {
            return 1 ;
        }
        if(index < 0){
            return 0 ;
        }

        if(dp[index][target] != -1) {
            return dp[index][target] ;
        }

        long long pick = 0, not_pick = 0 ; // at any index we can either pick or not pick the element -> so initially number of ways take 0 then we will add

        if(coins[index] <= target) {
            pick = memoization(coins, n, index , target - coins[index], dp) ; // since we can choose one coin any number of time so index would not change
        }

        not_pick= memoization(coins, n, index -1, target, dp) ; // if we choose to not pick the current element then decrease the index and no effect on target

        return dp[index][target]= pick + not_pick ;

    }
    long long int count(int coins[], int N, int sum) {
        // code here.
        return recursion(coins, N, N-1, sum) ;

        vector<vector<int>> dp (N , vector<int>(sum +1 , -1)) ;

        return memoization(coins, N , N-1, sum , dp) ;

    }
};