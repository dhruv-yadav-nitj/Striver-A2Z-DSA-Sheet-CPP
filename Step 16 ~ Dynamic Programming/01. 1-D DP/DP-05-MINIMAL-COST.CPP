#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve (vector<int>&height, int k , int dp[] , int index){
        // base condition
        if(index == 0){
            return 0 ;
        }

        if(dp[index] != -1){
            return dp[index] ;
        }

        int ans= INT_MAX ;
        for(int i = 1 ;i <= k ; i++){
            if(index - i >= 0){
                int jump = solve(height ,k , dp,  index- i) + abs(height[index]-height[index-i]) ;
                ans = min(ans , jump) ;
            }
        }

        return dp[index] =  ans ;

    }
    int minimizeCost(vector<int> &height, int n, int k)
    {
        // Code here
        int dp[n +1] ;
        for(int i = 0 ; i < n+1 ; i++){dp[i] = -1 ;}

        return solve(height , k , dp , n-1) ;
    }
};