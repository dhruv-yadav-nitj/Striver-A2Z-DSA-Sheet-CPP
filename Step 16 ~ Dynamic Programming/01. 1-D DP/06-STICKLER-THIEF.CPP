#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

// similar to prev problem

class Solution {
public:
    int FindMaxSum(int arr[], int n) {
        
        vector<int> dp(n, 0) ;
        dp[0] = arr[0] ;

        for(int i =1 ; i < n ; i++) {
            int pick = arr[i] ;
            // at any index we can either pick or not pick

            // when we pick -> we must to maximise the total sum by including the prev ka prev wla sum (since consecutive not allowed)
            if(i > 1){
                pick += dp[i-2] ;
            }
            // in notPick -> just continue with the abhi tk chalta hua sum
            int notPick = 0 + dp[i-1] ;
            
            dp[i] = max(pick, notPick) ;
        }

        return dp[n-1] ;
    }
};