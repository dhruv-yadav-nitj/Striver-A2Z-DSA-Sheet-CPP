#include <bits/stdc++.h>
using namespace std;

// gfg version

// approach #1 : using pick and not pick technique
class Solution {
public:
    void recursion (string s , int index, string temp , unordered_set<string>&st) {
        // base condition
        if(index == s.length()) {
            st.insert(temp) ;
            return ;
        }

        // pick
        temp += s[index] ; recursion(s, index +1 , temp, st) ;

        // backtrack and not pick
        temp.pop_back() ;
        recursion(s, index +1 , temp , st) ;
    }
    int distinctSubsequences(string s) {
        // Your code goes here
        unordered_set<string> st ;
        recursion(s, 0 , "" , st) ;

        return st.size() ;
    }
};

// approach #2 : using DP
// vvv. imp and good explanation : https://youtu.be/9UEHPiK53BA
class Solution {
  public:	
	int distinctSubsequences(string s) {
	    // code here

        int n = s.length() ;
        vector<int> dp (n +1 , 0) ;

        dp[0] =1 ; // for empty subsequence

        unordered_map<char, int> mp ;
        for(int i =1 ; i <= n ; i++) {
            if(mp.find(s[i-1]) == mp.end()) {
                mp[s[i-1]] = i ;
                dp[i] = dp[i-1]*2 ;
            }
            else{
                int prev= mp[s[i-1]] ;
                dp[i] = dp[i-1] * 2  - dp[prev -1]  ;

                // update the new occurence
                mp[s[i-1]]= i ;
            }
        }

        return dp[n] ;
	}
};

// leetcode version
// approach #1 : using recursion and memoization
class Solution {
public:
    int recursion (string s, string t, int i , int j)  {
        // base condition
        if(j < 0) {
            return 1 ;
        }
        if(i < 0) {
            return 0 ;
        }

        // if matched
        if(s[i]==t[j]) {
            // pick and not pick
            return recursion(s, t, i-1, j-1) + recursion(s, t, i-1, j) ;
        }
        else{
            // not matched
            return recursion(s, t, i-1, j) ;
        }
    }

    int memoization (string s,string t, int i ,int j , vector<vector<int>>&dp) {
        if(j < 0) {return 1 ;}
        if(i < 0) {return 0 ;}

        if(dp[i][j] != -1) {
            return dp[i][j] ;
        }

        // if match
        if(s[i] == t[j]) {
            return dp[i][j] = memoization(s, t, i-1, j -1, dp) + memoization(s, t, i-1, j, dp) ;
        }
        else{
            return dp[i][j] = memoization(s, t, i-1, j, dp) ;
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length() , m = t.length() ;
        vector<vector<int>> dp (n, vector<int>(m, -1)) ;

        return memoization(s, t, n -1 , m-1, dp) ;
    }
};