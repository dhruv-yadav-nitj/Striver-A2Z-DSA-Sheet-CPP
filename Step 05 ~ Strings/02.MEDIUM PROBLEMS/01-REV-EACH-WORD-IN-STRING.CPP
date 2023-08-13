#include <bits/stdc++.h>
using namespace std;

// basic implementation based problem
// https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1

class Solution {
public:
    string reverseWords(string s) {
        // code here.
        string ans = "" , temp = "" ; int n = s.length() ;
        for(int i =0 ; i <= n ; i++) {
            if(s[i] == '.' or i == n) {
                reverse(temp.begin(), temp.end()) ;
                ans += temp ; ans += "." ; temp = "" ;
            }
            else{
                temp += s[i] ;
            }
        }
        ans.pop_back() ; return ans ;

    }
};