#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time ~ O(pow(2, n) x pow(2, m))
    int recursion (string s1 , string s2 , int index1 , int index2) {
        // base condition
        if(index1 < 0 or index2 < 0) {return 0 ;}
        // like in earlier problem it was pick and not pick -> similarly in DP problems on strins -> it would be match and not match
        // characters at current indexes in both the strings matched, means we should consider it in our longest common subsequence so add 1 and search for previous indexes
        // match
        if(s1[index1] == s2[index2]) {
            return 1 + recursion(s1, s2, index1 -1 , index2 -1) ;
        }
        // not match
        // not matched -> so take max of the two possible cases
        else{
            return max(recursion(s1, s2, index1-1, index2) , recursion(s1, s2, index1,  index2 -1)) ;
        }
    }

    int memoization (string s1, string s2, int ind1 , int ind2, vector<vector<int>>&dp) {
        // base condition
        if(ind1 < 0 or ind2 < 0) {return 0 ;}

        if(dp[ind1][ind2] != -1) {
            return dp[ind1][ind2] ;
        }

        // match
        if(s1[ind1] == s2[ind2]) {
            return dp[ind1][ind2] = 1 + memoization(s1, s2, ind1 -1, ind2 -1, dp) ;
        }
        else{
            return dp[ind1][ind2] = max(memoization(s1, s2, ind1-1, ind2, dp) , memoization(s1, s2, ind1, ind2-1, dp)) ;
        }
    }
    int lcs(int x, int y, string s1, string s2) {
        // your code here

        // return recursion(s1, s2, x -1, y -1) ;

        vector<vector<int>> dp (x, vector<int>(y , -1)) ;
        return memoization(s1, s2, x-1, y-1, dp) ;

    }
};