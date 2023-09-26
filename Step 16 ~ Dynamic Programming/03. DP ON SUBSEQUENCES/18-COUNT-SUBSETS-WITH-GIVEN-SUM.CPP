#include <bits/stdc++.h>
using namespace std;

// https://rb.gy/cff84

int memo (vector<int>&arr, int n, int i, int sum, vector<vector<int>>&dp) {
    // base condition
    if(sum ==0){return 1 ;} // this base condition is very controversial(not exactly) -> this would work only when we are given that none of the elements are zero -> because if any element is zero and uske aane se phle hi sum ==0 -> then it would always return 1 from here only without checking the element which was zero -> if we include the elements which are zero we can get extra subset, which will give the correct ans --> more proper explanation -->
    // https://takeuforward.org/data-structure/count-partitions-with-given-difference-dp-18/
    if(i == n-1){return arr[i] == sum ;}
    if(dp[i][sum] != -1){return dp[i][sum] ;}

    int pick(0), notPick(0), mod(1e9+7) ;
    if(arr[i] <= sum){
        pick = memo(arr, n, i+1, sum - arr[i], dp) ;
    }
    notPick = memo(arr, n, i+1, sum, dp) ;
    return dp[i][sum] = ((pick)%mod + (notPick)%mod)%mod ;
}

int findWays(vector<int> &arr, int k) {

    int n = arr.size() ;
    vector<vector<int>> dp(n, vector<int>(k+1, -1)) ;
    return memo(arr, n, 0, k, dp) ;
    
}
