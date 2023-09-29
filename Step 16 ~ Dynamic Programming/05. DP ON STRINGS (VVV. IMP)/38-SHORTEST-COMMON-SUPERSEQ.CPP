#include <bits/stdc++.h>
#define ll long long
using namespace std;

// len(shortest supersequence) = len(string1) + len(string2) - len(lcs)
// intution -> supersequence means combining both the strings -> now the subsequence which is common in both the strings -> would be added two times -> so we need to remove that subsequence (minus one time the length of common subsequence) -> since the problem asked for shortest supersequence -> minus the longest common subsequence from the max supersequence we can get (i.e., sum of length of both the strings)
// printing shortest common supersequence -> just follow the dp vector values (as done in Printing LCS wla Problem)
// https://leetcode.com/problems/shortest-common-supersequence/
// https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        // step 1 : first we need to fill the dp array
        int n=s.length(), m = t.length() ;
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0)) ;
        for(int i=1 ; i <= n ; i++) {
            for(int j =1 ; j <= m ; j++) {
                if(s[i-1]==t[j-1]){dp[i][j] = 1 + dp[i-1][j-1];}
                else{
                    dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }
        int len = n + m - dp[n][m] ; // length of shortest supersequence
        string ans = "" ; int i = n , j = m ;
        while(i > 0 and j >0){
            if(s[i-1]==t[j-1]) {
                ans += s[i-1] ; // means current character is a part of lcs (include only one time)
                i--, j-- ;
            }
            else{
                // if s[i-1] != t[j-1] -> it may come from two directions, either from i-1, j or i, j-1 -> we need to get into that direction in which value is greater
                if(dp[i-1][j] > dp[i][j-1]){
                    ans += s[i-1] ; i-- ;
                }
                else{
                    ans += t[j-1] ; j-- ;
                }
            }
        }
        while(i > 0) { ans += s[i-1]; i--; }
        while(j > 0) { ans += t[j-1]; j--; }
        reverse(ans.begin(), ans.end()) ; return ans ;
    }
};