#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Follow Up : DP 22 : Target Sum

class Solution {
public:
    int countPartitions(int n, int d, vector<int> &arr) {
        
        // let s1 and s2 be the sum of two subsets -> s1 - s2 = d and s1 + s2 = total Sum -> solving -> s1 = (totalSum + d)/2 
        int totalSum = accumulate(arr.begin() , arr.end(), 0) ;
        int s1, s2 ;
        if(totalSum < d) {return 0 ;} // it is obviously not possible

        if((totalSum+d)%2 ==1){return 0 ;} // odd sum not possible according to maths

        vector<vector<int>> dp (n, vector<int>((totalSum+d)/2+1, -1)) ;
        return memo(arr, n, 0, (totalSum+d)/2, dp) ;
        
    }
    int memo (vector<int>&arr, int n, int i, int target, vector<vector<int>>&dp) {
        // base condition
        if(i == n-1){
            if(target == 0 and arr[i] == 0){
                // in this case we can either pick or not pick the last element which is zero as it would not do any changes to target which is also zero
                return 2 ;
            }
            else if(target == arr[n-1] or target == 0) {return 1 ;}
            else{
                return 0 ;
            }
        }

        if(dp[i][target] != -1){return dp[i][target] ;}

        int pick (0), notPick (0) ; int mod = (1e9 + 7) ;

        if(arr[i] <= target ){
            pick = memo(arr, n, i+1, target - arr[i], dp) ;
        }
        notPick = memo(arr, n, i+1, target, dp) ;

        return dp[i][target] = (pick%mod + notPick%mod) %mod ;
    }
};