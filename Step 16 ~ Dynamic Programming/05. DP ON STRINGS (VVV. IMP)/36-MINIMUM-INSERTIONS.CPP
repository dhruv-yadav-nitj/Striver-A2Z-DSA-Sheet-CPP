#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// again a follop up problem of LCS

// min insertions to make a string palindromic is -> (len of string) - (longest palindromic subsequence)

class Solution {
public:
    int minInsertions(string s) {
        int n= s.length() ;
        string t=s; reverse(t.begin(), t.end()) ;
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0));
        for(int i=1; i <= n ; i++) {
            for(int j=1; j <= n ; j++) {
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
        int len = dp[n][n] ;
        return n - len ;
    }
};