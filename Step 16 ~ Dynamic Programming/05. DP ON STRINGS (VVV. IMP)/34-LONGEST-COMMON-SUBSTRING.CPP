#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://takeuforward.org/data-structure/longest-common-substring-dp-27/


// APPROACH: can be considered a follow up ques to DP-32
// dp[n][m] will not give us the answer; rather the maximum value in the entire dp array will give us the length of the longest common substring. This is because there is no restriction that the longest common substring is present at the end of both the strings.

class Solution {
public:
    int longestCommonSubstr(string s, string t, int n, int m) {
        // taking the max value from dp array to form the longest common substring
        int ans(0) ;
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0)) ;
        for(int i =1 ;i <= n ; i++) {
            for(int j =1; j <= m; j++) {
                // case 1 : matches
                if(s[i-1] == t[j-1]) {
                    dp[i][j]=1 + dp[i-1][j-1] ;
                    ans = max(ans, dp[i][j]) ;
                }
                else{
                    // if not matched -> starts  from zero again (since substring is continuous, and if the characters are different -> consecutiveness of the the substring is broken)
                    dp[i][j] =0 ;
                }
            }
        }
        return ans ;
    }
};