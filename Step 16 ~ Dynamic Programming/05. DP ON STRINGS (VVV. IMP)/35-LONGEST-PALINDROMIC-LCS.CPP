#include <bits/stdc++.h>
#define ll long long
using namespace std;

// logic is very clear -> palindrome means -> it is same from start as well as from end -> so how can we use LCS (which is used to find longest common subsequence for 2 strings, i say 2) , to find longest palindromic subsequence of 1 string, i say 1 -> so we can reverse the given string to form a new string -> such as bbabcbcab -> longest subsequence which is also palindromic is babcbab -> so if we reverse the given string we get -> bacbcbabb -> so this reversed string would also have the same palindromic longest subsequence -> since the subsequence was palindromic -> we can get that into given as well as reverse string -> so this would be common in both the given string as well as in the reverse string
// approach: so string1 (given) -> reverse this string -> get string2 -> find the lcs of these two strings , the ans would be necessarily palindromic longest subequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t= s; reverse(t.begin(), t.end()) ;
        int n =s.length() ;
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0)) ;
        for(int i=1; i <= n; i++) {
            for(int j=1; j<= n; j++) {
                if (s[i-1]==t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]) ;
                }
            }
        }
        return dp[n][n];
    }
};