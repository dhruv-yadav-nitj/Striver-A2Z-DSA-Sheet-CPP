#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        // code here
        
        // step 1 : finding the lcs length
        vector<vector<int>> dp (m +1 , vector<int>(n+1 , 0)) ; // X is represented in the row indexes and Y is represented as col indexes

        for(int i =1 ; i <= m ; i++) {
            for(int j = 1 ; j <= n; j++) {
                // match
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }
                // not matched
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }

        // step 2 : supersequence = (total length of both strings) - (length of lcs)
        // intution : we choose every character of both strings and add them to make one new string -> but notice that we those characters woule be two times in this new string which were common in both strings -> so in order to make this new string shortest -> we need to delete the longest common sequence from this new string to make it shortest
        int lcs = dp[m][n] ; int super = (m+ n)-lcs ; // supersequence = total length  - lcs length

        // step 3 : getting the shortest supersequence (there can be many ans to this)
        string ans = "" ; int i = m , j = n ;
        while(i > 0 and j > 0) {
            if(X[i-1] == Y[j-1]) {
                ans += X[i-1] ; --i , --j ;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += X[i-1] ;
                --i ;
            }
            else{
                ans += Y[j-1] ;
                --j ;
            }
        }

        // add remaining characters
        while(i > 0) {
            ans += X[i-1]; --i ;
        }
        while(j > 0) {
            ans += Y[j-1] ; --j ;
        }

        reverse(ans.begin() , ans.end()) ;
        cout << ans << endl ; // shortest super-sequence
        return super ; // length
    }
};