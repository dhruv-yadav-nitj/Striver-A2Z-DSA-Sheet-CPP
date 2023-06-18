#include <bits/stdc++.h>
using namespace std ;

// using simple recursion
int fibonacci_recursion (int n){
    // base condition
    if(n <= 1){
        return n ;
    }

    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2) ;
}

// using memoization
int fibonacci_mem (int n , int dp[]) {

    if(n <= 1){
        return n ;
    }

    if(dp[n] != -1){
        return dp[n] ;
    }

    return dp[n] = fibonacci_mem(n-1 , dp) + fibonacci_mem(n-2 , dp) ;
}

// using tabulation method
int fibonacci_tab (int n, int dp[]){
    // from base case to final answer
    dp[0] = 0 ; dp[1] = 1 ;

    for(int i =2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2] ;
    }

    return dp[n] ;
}

// space optimisation
int fibonacci_sp (int n){

    int prev1 = 1 , prev2 = 0;
    for(int i=2 ; i <= n ; i++){
        int curr = prev1 + prev2 ;
        prev2= prev1 , prev1 = curr ;

    }

    return prev1 ;
}


int main () {

    int n ; cin >> n ;
    
    // extra array for dp solutions
    int dp[n+1] ;// n+1 because of 0-based indexing
    for(int i=0; i < n+1 ; i++){
        dp[i] = -1 ;
    }

    cout << fibonacci_recursion(n) << " " << fibonacci_mem(n , dp) << " " << fibonacci_tab(n , dp) << " " << fibonacci_sp(n) << endl ;

}