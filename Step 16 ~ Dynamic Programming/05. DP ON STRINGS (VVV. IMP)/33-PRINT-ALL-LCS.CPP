#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
// https://www.youtube.com/watch?v=-zI4mrF2Pb4
// iska intuition ke baar dp array banakr aaega from prev problem
// take example like s1=abcde and s2=bdgek

class Solution {
public:
    vector<string> all_longest_common_subsequences(string s, string t) {

        // to print all the lcs -> first we need the length of lcs -> which can be found using previous problem's approach
        int n=s.length(), m=t.length() ;
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0)) ;
        for(int i =1 ;i <= n ; i++) {
            for(int j =1; j <= m; j++) {
                // case 1 : matches
                if(s[i-1] == t[j-1]) {
                    dp[i][j]=1 + dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
                }
            }
        }

        int lcs=dp[n][m] ;
        set<string> st; fn(s, t, n, m, lcs, "", st) ;

        vector<string> ans (st.begin(), st.end()); return ans ;
    }
    void fn (string s, string t, int n, int m, int lcs, string curr, set<string>&st) {
        // base case
        if(curr.length() == lcs) {
            // bcz strings come into reverse order -> since we are starting from the end
            reverse(curr.begin(), curr.end()); st.insert(curr) ;
            return ;
        }

        for(int i=n; i>0; i--){
            for(int j=m; j >0 ; j--) {
                if(s[i-1]==t[j-1]){ fn(s, t,i-1, j-1, lcs, curr+s[i-1], st) ;}
            }
        }
    }
};