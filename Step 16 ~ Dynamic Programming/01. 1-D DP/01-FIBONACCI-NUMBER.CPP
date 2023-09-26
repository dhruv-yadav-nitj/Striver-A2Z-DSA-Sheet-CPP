#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (int x) {
        // base condition
        if(x <= 1){return x ;}
        // in any other case -> return the sum of prev two elements
        return recursion(x-1) + recursion(x-2) ;
    }
    int memoization (int x){
        vector<int> dp(100, -1) ;
        return helper(x, dp) ;
    }
    int helper (int x, vector<int>&dp) {
        // base condition 
        if(x <=1 ){return x ;}

        if(dp[x] != -1){return dp[x] ;}

        return dp[x] = helper(x-1, dp)+helper(x-2, dp) ;
    }
    int tabulation (int x) {
        if(x <= 1){return x ;}
        vector<int> dp(100, -1) ; // this can be used to find fibonacci upto 99
        dp[0] =0; dp[1] = 1 ;

        for(int i = 2 ; i <= x ; i++) {
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        return dp[x] ;
    }
    int spaceOptimised (int x ){
        if(x <= 1){return x ;}
        int prev1= 1 , prev2 = 0 ;
        for(int i = 2 ; i <= x ; i++) {
            int curr = prev1 + prev2 ;
            prev2 = prev1 ; prev1 = curr ;
        }
        return prev1 ;
    }
};

int main () {
    int x; cin >> x ;
    Solution obj ; cout << obj.recursion(x) << endl;
    cout << obj.memoization(x) << endl ; cout << obj.tabulation(x) << endl ;
    cout << obj.spaceOptimised(x) << endl ;
}