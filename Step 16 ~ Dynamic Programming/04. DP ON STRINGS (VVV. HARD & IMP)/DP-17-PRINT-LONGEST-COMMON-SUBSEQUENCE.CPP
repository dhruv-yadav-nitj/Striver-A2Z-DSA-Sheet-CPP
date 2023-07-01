#include <bits/stdc++.h>
using namespace std ;

string lcs (string s1 , string s2, int n , int m) {
    // in this problem we need to find the longest common subsequence among s1 and s2 (print the lcs string and not its length)

    // we would be using tabulation method to find the LCS (requirement -> prev problem)
    // this problem is continued from prev problem

    // tabulation method to find the lcs

    vector<vector<int>> dp (n+1 , vector<int> (m+1, 0)) ; // 1-based indexing 
    // rows -> s1 and col -> s2

    for(int i =1 ;i <= n ; i++) {
        for(int j = 1 ;  j<= m ; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j]= 1 + dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
            }
        }
    }

    int len = dp[n][m] ;

    // so now we would be using this dp 2d vector to find our lcs

    string ans (len , '0'); int index = len-1 ; // we can also take a normal empty string and add each letter in this string and at last just reverse this string
    int i = n , j = m ;
    while(i >0 and j > 0) {
        // match
        if(s1[i - 1] == s2[j - 1]) {
            ans[index] = s1[i-1] ;
            index-- , --i , --j ;
        }
        // not match
        else{
            if(dp[i-1][j] > dp[i][j-1]) {
                --i ;
            }
            else{
                --j ;
            }
        }
    }

    return ans ;
}