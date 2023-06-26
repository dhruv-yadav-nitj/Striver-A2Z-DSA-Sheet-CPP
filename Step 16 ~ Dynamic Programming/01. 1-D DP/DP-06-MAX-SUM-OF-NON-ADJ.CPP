#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    // step 1 : build basic recursion solution
    int recursion (int arr[], int n){
        if(n == 0){
            return arr[0]; 
        }
        if(n < 0){
            return 0 ;
        }

        // pick
        int sum1 = arr[n] + recursion(arr, n -2) ;

        // not pick
        int sum2 = 0 + recursion(arr, n-1) ;

        return max(sum1 , sum2) ;
    }

    // step 2 : memoization
    int memoization (int arr[], int index, int dp[]){
        if(index == 0){
            return arr[0] ;
        }

        if(index < 0){
            return 0 ;
        }

        if(dp[index] != -1){
            return dp[index] ;
        }

        // pick
        int sum1 = arr[index] + memoization(arr, index -2, dp) ;

        // not pick
        int sum2 = 0 + memoization(arr, index-1, dp) ;

        return dp[index] = max(sum1 , sum2) ;

    }
    
    // step 3 : tabulation
    int tabulation (int arr[], int n){
        
        // why bother when the array has only 1 element
        if(n == 1){
            return arr[0] ;
        }

        // create the dp array
        int dp[n] ; for(int i =0; i < n ; i++){dp[i] = -1 ;}

        // set the base cases
        dp[0] = arr[0] ;
        for(int i = 1 ; i < n ; i++){

            // pick
            int sum1 = arr[i] ;
            if(i - 2 >= 0){
                sum1 += dp[i-2] ;
            }

            // not pick
            int sum2 = 0 + dp[i-1] ;

            dp[i] = max(sum1 , sum2) ;
        }

        return dp[n-1] ;
    }

    // step 4 : space optimisation
    int optimised(int arr[] , int n){

        if(n==1){
            return arr[0] ;
        }

        int prev1, prev2, curr ;
        // prev1  is calculated using the pick and not pick applied at index = 1
        // if we pick arr[1] then we cant pick arr[0] and if we dont pick arr[1] then we can pick arr[0]
        prev2 = arr[0] ; prev1 = max(arr[1] , 0 + arr[0]) ;
        for(int i=2 ; i < n ; i++){

            // pick and not pick
            curr = max(arr[i] + prev2 , 0 + prev1) ;

            // udpate the values
            prev2 = prev1 , prev1 = curr ;
        }

        return prev1 ;

    }

    int findMaxSum(int *arr, int n){
        // code here

        // method 1 : using simple recursion
        return recursion (arr, n-1) ;

        // method 2 : using memoization
        int dp[n] ; for(int i =0; i < n ; i++){dp[i] =-1;}
        return memoization(arr, n-1 , dp) ;

        return tabulation(arr, n) ;
    }
};