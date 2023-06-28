#include <bits/stdc++.h>
using namespace std;

// Try 1 : Self Try
class Solution
{
public:
    bool recursion(vector<int> &arr, int n, int index, int sum)
    {
        // base conditions
        if (sum == 0)
        {
            return true;
        }
        if (index == n)
        {
            return false;
        }

        if (arr[index] <= sum)
        {
            // pick
            if (recursion(arr, n, index + 1, sum - arr[index]))
            {
                return true;
            }
        }

        // not pick
        if (recursion(arr, n, index + 1, sum))
        {
            return true;
        }

        // if both the cases does not return ans
        return false;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        return recursion(arr, arr.size(), 0, sum);
    }
};
// one mistake i am doing that I am thinking always in bottom-up direction
// but for memoisation we need to think in top-down direction for writing recursive solution

class Solution {
public:
    bool recursion (vector<int>&arr, int index , int target) {
        // base conditions
        if(target ==0) {return true ;}
        if(index ==0) {
            // we have reached the bottom
            // now we have only one choice to choose the arr[0] -> if it is equal to target then yes return true else false
            return (arr[index] == target) ;
        }

        // at any index we have two choices either to pick it or not pick it (if we pick then it should not be greater than target)
        bool pick = false, not_pick = false ;

        if(arr[index] <= target) {
            pick = recursion(arr, index -1 , target -arr[index]) ;
        }

        not_pick = recursion(arr, index -1 , target) ;

        return (pick or not_pick) ; // if any of them returns true then return true
    }
    bool memoization (vector<int>&arr, int index, int target, vector<vector<int>>&dp) {
        // base condition
        if(target ==0) {
            return true ;
        }
        if(index ==0) {
            return (arr[index] == target) ;
        }

        if(dp[index][target] != -1) {
            return dp[index][target] ;
        }

        bool pick= false , not_pick = false ;
        // pick
        if(arr[index] <= target) {
            pick = memoization(arr, index -1 , target - arr[index], dp) ;
        }

        // not pick
        not_pick = memoization(arr, index -1 , target , dp) ;

        return dp[index][target] = (pick || not_pick) ;

    }
    bool isSubsetSum(vector<int> arr, int sum) {
        // code here
        int n = arr.size() ;
        return recursion(arr, n -1 , sum) ;

        // intuition of memoisation -> since a particular state depends on two factors index and target -> so the memoization would also be based on these two factors only
        // so index can be 0, 1, 2, 3, .... , n-1 and target can be 0, 1, 2, 3, .... sum -> so we need a grid of n x (sum +1) size
        vector<vector<int>> dp (n , vector<int> (sum+1, -1));
        return memoization(arr, n-1, sum , dp) ;
    }
};