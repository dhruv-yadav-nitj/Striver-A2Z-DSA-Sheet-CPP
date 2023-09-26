#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion (string s, string t , int i , int j) {
        // base condition
        if(i < 0) {
            return j+1 ;
            // insert remaining characters
        }
        if(j < 0) {
            return i +1 ;
            // remove extra characters
            // it also applies when both i < 0 and j < 0 at same time -> in this case it would return -1 + 1 = 0 -> that's perfect
        }

        // match
        if(s[i] == t[j]) {
            return recursion(s, t, i-1, j-1) ;
            // if the corresponding characters in both string matches -> that's the best case -> we need not do anything at this point
            // return 0 + recursion (s, t, i-1, j-1) -> 0 signifies we did not do anything at this step
        }
        // not-matched
        else{
            // here we can do three things -> insert , remove and replace
            int insert = 1 + recursion(s, t, i, j-1) ; // we added this character s[j] to the right of s[i] -> so j shrinks but i whi ka whi rh gya
            int replace = 1 + recursion(s, t, i-1, j-1) ; // we replaces the character -> both are happy -> shrink both strings
            int rem = 1 + recursion(s, t, i-1 , j) ; // we remove this character in s -> so i shrinks but j remains same as its not satisfied yet

            return min(min(insert, replace), rem) ;
        }
    }
    
    int memoization (string &s, string &t, int i, int j, vector<vector<int>>&dp) {
        // base condition
        if(i< 0) {
            return j +1 ;
        }
        if(j < 0) {
            return i +1 ;
        }

        if(dp[i][j] != -1){return dp[i][j] ;}

        // match
        if(s[i] == t[j]) {
            return dp[i][j] = 0 + memoization(s, t, i-1, j-1, dp) ;
        }
        else{
            // not matched
            return dp[i][j] = 1 + min(min(memoization(s, t, i, j-1, dp), memoization(s, t, i-1, j, dp)) , memoization(s, t, i-1, j-1, dp)) ;
            // either insert , remove , replace
        }
    }

    int editDistance(string s, string t) {
        // code here
        int n = s.length() , m = t.length() ;
        
        return recursion(s, t, n-1, m-1) ;

        vector<vector<int>> dp (n , vector<int> (m , -1)) ;
        return memoization(s, t, n -1, m -1, dp) ;

    }
};