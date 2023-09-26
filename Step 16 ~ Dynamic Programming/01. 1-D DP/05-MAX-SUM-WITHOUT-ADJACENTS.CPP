#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

// approach #1 : did myself
class Solution {
public:
    int recursion (int arr[], int n, int prev, int curr, int sum) {

        if(curr == n){return sum;}
        int pick (0), notPick (0) ;
        // pick and not-pick -> pick iff prev < curr -1
        if(prev < curr-1){
            pick = recursion(arr, n, curr, curr+1, sum+arr[curr]) ;
        }
        // notPick is always an option
        notPick = recursion(arr, n, prev, curr+1, sum) ;

        return max(pick, notPick) ;
    }

    int findMaxSum(int *arr, int n) {
        return recursion(arr, n , -2, 0, 0) ;
    }
};

// the catch is that we dont even need prev index, then how ? -->
class Solution {
public:
    int recursion (int arr[], int n, int index){
        
        // base conditions
        if(index ==0){return arr[0] ;}
        if(index < 0){return 0 ;}

        int pick(0), notPick (0) ;

        // instead of relying on prev index -> if we are picking the current index then we will directly send the recursion call for next ka next element and not for the adjacent element
        pick = arr[index] + recursion(arr, n, index -2) ;

        // not picking is always an option
        notPick = 0 + recursion(arr, n , index-1) ;

        return max(pick, notPick) ;
    }
    int findMaxSum(int *arr, int n) {
        return recursion(arr, n, n-1) ;

        vector<int> dp (n,  -1) ;
        return memoization(arr, n, n-1, dp);
    }

    int tabulation (int arr[], int n) {

        if(n==1){
            return arr[0] ;
        }

        vector<int> dp (n, 0) ; dp[0] = arr[0] ; dp[1] = max(arr[1], arr[0]) ;
        for(int i =2; i < n ; i++) {
            dp[i] = max(arr[i] + dp[i-2], dp[i-1]) ;
            // at any index either we can choose from -> selecting current element + prev ka prev jo chala aa rha tha sum or we can ignore current element aur jo peeche chala aa rha tha usko continue krna
        }

        return dp[n-1] ;

    }

    int memoization (int arr[], int n, int curr, vector<int>&dp) {
        if(curr ==0){return arr[0] ;}
        if(curr < 0){return 0 ;}

        if(dp[curr] != -1){return dp[curr] ;}

        int pick (0) , notPick (0) ;
        pick = arr[curr] + memoization(arr, n, curr-2, dp) ;

        notPick = 0 + memoization(arr, n, curr -1, dp) ;

        return dp[curr]= max(pick, notPick);
    }
};