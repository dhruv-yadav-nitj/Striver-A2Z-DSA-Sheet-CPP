#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/
// in most of the string based problems -> memoization would give TLE -> so we need to implement tabulation to pass all the test cases

class Solution {
public:
    int lcs (string s1, string s2) {
        // tabulation
        // since we cant represent -ve indexes in the vector -> we would do shifting of indexes -> -1 would be 0 , 0 would be 1 and so on..
        int n= s1.length(), m = s2.length();
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0)) ;
        for(int i=1 ; i <= n; i++) {
            for(int j=1; j <= m ; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }
                else{
                    dp[i][j]=max(0 + dp[i-1][j] , 0 + dp[i][j-1]) ;
                }
            }
        }
        return dp[n][m] ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(), n2= text2.length() ;
        vector<vector<int>> dp (n1, vector<int>(n2, -1));
        return memo(text1, text2, n1-1, n2-1, dp) ;
    }
    int memo (string s1, string s2, int ind1, int ind2, vector<vector<int>>&dp) {
        // base condition
        if(ind1 <0 or ind2 <0) {return 0;}

        if(dp[ind1][ind2] != -1) {return dp[ind1][ind2] ;}

        int ans =0;
        // match or not match

        if(s1[ind1] == s2[ind2]) {
            // character matches
            ans = 1 + memo(s1, s2, ind1-1, ind2-1, dp) ;
        }
        else{
            // reduce either of the string
            ans = max(memo(s1, s2, ind1-1, ind2, dp), memo(s1, s2, ind1, ind2-1, dp)) ;
        }
        return dp[ind1][ind2]=ans ;
    }
};