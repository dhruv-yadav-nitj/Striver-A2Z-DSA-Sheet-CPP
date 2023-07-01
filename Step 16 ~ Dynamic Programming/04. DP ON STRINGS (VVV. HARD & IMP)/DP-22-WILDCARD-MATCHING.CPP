#include <bits/stdc++.h>
using namespace std;

// [HARD]

class Solution {
public:
    // s -> pattern and t -> normal string
    bool recursion (string s, string t, int i , int j) {
        // base condition
        if(i < 0 and j < 0) {
            // both got exhausted
            return true ;
        }
        else if(i < 0 and j >=0) {
            // since s was not able to match with t and got finished early
            return false ;
        }
        else if(i >= 0 and j < 0) {
            // if only t got exhausted and s is still remaining -> then in this case remaining characters of s should all be * only
            while(i >= 0) {
                if(s[i] != '*'){
                    return false ;
                }
                --i ;
            }
            return true ;
        }


        if(s[i] == t[j]) {
            return recursion(s, t, i-1, j-1) ;
        }
        else if(s[i] == '?'){
            return recursion(s, t, i-1, j-1) ;
        }
        else if(s[i] == '*'){
            bool enough = recursion(s, t, i-1, j) ; // means * was used to represent till this character only
            bool notYet = recursion(s, t, i , j-1) ; // no * would be used to represent more left characters
            return (enough or notYet) ;
        }
        else{
            return false ;
        }
    }

    bool memoization (string &s, string &t, int i , int j , vector<vector<int>>&dp) {
        // base condition
        if(i < 0 and j < 0) {
            // both got exhausted
            return true ;
        }
        else if(i < 0 and j >=0) {
            // since s was not able to match with t and got finished early
            return false ;
        }
        else if(i >= 0 and j < 0) {
            // if only t got exhausted and s is still remaining -> then in this case remaining characters of s should all be * only
            while(i >= 0) {
                if(s[i] != '*'){
                    return false ;
                }
                --i ;
            }
            return true ;
        }

        if(dp[i][j] != -1) {
            return dp[i][j] ;
        }

        if(s[i] == t[j]) {
            return dp[i][j] = recursion(s, t, i-1, j-1) ;
        }
        else if(s[i] == '?'){
            return dp[i][j] = recursion(s, t, i-1, j-1) ;
        }
        else if(s[i] == '*'){
            bool enough = recursion(s, t, i-1, j) ; // means * was used to represent till this character only
            bool notYet = recursion(s, t, i , j-1) ; // no * would be used to represent more left characters
            return dp[i][j] = (enough or notYet) ;
        }
        else{
            return dp[i][j] = false ;
        }

    }

    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.length() , m = str.length() ;
        return recursion(pattern, str, n-1, m-1) ;

        vector<vector<int>> dp (n , vector<int>(m , -1)) ;
        return memoization(pattern, str, n-1, m-1, dp) ;

    }
};