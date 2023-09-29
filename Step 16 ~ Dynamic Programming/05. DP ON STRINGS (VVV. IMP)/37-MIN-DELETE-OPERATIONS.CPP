#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/delete-operation-for-two-strings/

// since we have to find the min deletion operation to make two strings equal -> we can assume there must be some subsequence common in both the strings -> so we would find the longest common subsequence b/w both the strings -> then ans would be removing by extra characters from both the strings which are not part of lcs

class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.length(), m = t.length() ;
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0));
        for(int i=1 ; i <= n ; i++) {
            for(int j=1 ; j <= m ; j++) {
                if(s[i-1]==t[j-1]){dp[i][j] = 1 + dp[i-1][j-1] ;}
                else{
                    dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        int len = dp[n][m], ans=0 ; if(n > len){ans+=n-len;} if(m>len){ans += m-len;}
        return ans ;
    }
};