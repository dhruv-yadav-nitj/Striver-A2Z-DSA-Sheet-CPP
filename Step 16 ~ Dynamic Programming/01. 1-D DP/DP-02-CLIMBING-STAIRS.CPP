#include <bits/stdc++.h>
using namespace std ;

// recursive solution
int solve1 (int n){
    if(n== 0 or n==1){
        return 1 ;
    }

    return solve1(n-1) + solve1(n-2) ;

}

// memoization solution
int solve2 (int n , vector<int>&dp){

    if(n <= 1){
        return 1 ;
    }

    if(dp[n] != -1){
        return dp[n] ;
    }

    return dp[n] = dp[n-1] + dp[n-2] ;
}    

// tabulation
int solve3 (int n , vector<int>&dp){

    dp[0]= 1 , dp[1]= 1 ;

    for(int i=2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2] ;
    }

    return dp[n] ;

}

// space optimised tabulation
int solve4 (int n){

    int prev1= 1 , prev2 =1 ;
    for(int i=2 ; i <= n ; i++){

        int curr = prev1 + prev2 ;
        prev2 =prev1 , prev1 = curr ;
    }

    return prev1 ;
}

// accepted solution --> since we were required to modulus it
int solve5 (int n){

    int prev1= 1 , prev2 =1 ;
    for(int i=2 ; i <= n ; i++){

        int curr = (prev1 + prev2)%((int)(1e9 + 7)) ;
        prev2 =prev1 , prev1 = curr ;
    }

    return prev1 ;
}

class Solution{
public:    
    int countWays(int n){
        // your code here
        
        // vector<int> dp (n +1  , -1) ;

        return solve4 (n) ;
        
    }
};