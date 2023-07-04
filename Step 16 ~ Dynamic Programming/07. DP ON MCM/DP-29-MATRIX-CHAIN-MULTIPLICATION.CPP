#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (int arr[], int i , int j) {
        // base condition
        if(i == j) {
            return 0 ;
        }
        int mini =INT_MAX ;
        for(int k = i ; k < j ; k++) {
            int curr = (arr[i-1] * arr[k] * arr[j]) + recursion(arr, i , k) + recursion(arr, k+1, j) ;
            mini = min(mini , curr);
        }

        return mini ;

    }

    int memoization (int arr[], int i , int j, vector<vector<int>>&dp) {
        // base condition
        if(i == j) {
            return 0 ;
        }
        if(dp[i][j] != -1) {return dp[i][j] ;}
        int mini =INT_MAX ;
        for(int k = i ; k < j ; k++) {
            int curr = (arr[i-1] * arr[k] * arr[j]) + recursion(arr, i , k) + recursion(arr, k+1, j) ;
            mini = min(mini , curr);
        }

        return dp[i][j] = mini ;

    }

    int tabulation (int arr[], int n) {
        vector<vector<int>> dp (n , vector<int> (n , -1)) ;
        // just follow the step -> copy the base case as it is -> copy the recursion -> return appropriate dp[i][j] 
        // in the memoization -> base case -> for all i == j -> return 0
        for(int i =0 ; i < n ; i++) {
            dp[i][i] = 0 ;
        }

        for(int i = n -1 ; i >= 1 ; i--) {
            for(int j = i +1 ; j < n ; j++) {
                int mini = INT_MAX ;
                for(int k = i ; k < j ; k++) {
                    int curr = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]) ;
                    mini =min(mini, curr) ;
                }
                dp[i][j] = mini ;
            }
        }

        return dp[1][n-1] ;

    }
    
    int matrixMultiplication(int N, int arr[]) {
        // code here
        
        return recursion(arr, 1, N -1) ;

        vector<vector<int>> dp (N , vector<int> (N, -1)) ;
        return memoization(arr, 1, N-1, dp) ;

        return tabulation(arr, N) ;

    }
};