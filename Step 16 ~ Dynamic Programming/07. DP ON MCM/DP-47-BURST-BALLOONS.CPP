#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (vector<int>&arr, int i, int j) {
        // base condition
        if(i > j){return 0 ;}
        int maxi= INT_MIN ;
        for(int k = i ; k <= j; k++) {
            int curr = arr[k] * arr[i-1] * arr[j +1]  + recursion(arr, i , k-1) + recursion(arr, k +1, j) ;
            maxi = max(maxi, curr) ;
        }

        return maxi ;

    }

    int memoization (vector<int>&arr, int i, int j,vector<vector<int>>&dp) {
        // base condition
        if(i > j){return 0 ;}
        if(dp[i][j] != -1) {
            return dp[i][j] ;
        }
        int maxi= INT_MIN ;
        for(int k = i ; k <= j; k++) {
            int curr = arr[k] * arr[i-1] * arr[j +1]  + memoization(arr, i , k-1, dp) + memoization(arr, k +1, j, dp) ;
            maxi = max(maxi, curr) ;
        }

        return dp[i][j] =maxi ;

    }

    int tabulation (vector<int>&arr, int n) {

        arr.push_back(1) ; arr.insert(arr.begin() , 1) ;
        vector<vector<int>> dp (n+2 , vector<int> (n+2 , 0)) ;

        for(int i = n ; i >= 1 ; i--) {
            for(int j = 1 ; j <= n ; j++) {
                if (i > j){continue; }
                int maxi = INT_MIN ;
                for(int k = i ; k <= j ; k++) {
                    int curr = arr[i-1]* arr[k] *arr[j+1] + dp[i][k-1] + dp[k +1][j] ;
                    maxi = max(maxi , curr) ;
                }
                dp[i][j] = maxi ;
            }
        }

        return dp[1][n] ;

    }

    int maxCoins(int N, vector<int> &arr) {
        // code here
        int n = N ;
        // step 1 : append 1 to start and end of the given array
        arr.push_back(1) ; arr.insert(arr.begin() ,1 );
        return recursion(arr, 1, N) ;

        vector<vector<int>> dp (n +1 , vector<int>(n +1 , -1)) ;
        return memoization(arr, 1, n, dp) ;

        return tabulation(arr, n) ;
    }
};