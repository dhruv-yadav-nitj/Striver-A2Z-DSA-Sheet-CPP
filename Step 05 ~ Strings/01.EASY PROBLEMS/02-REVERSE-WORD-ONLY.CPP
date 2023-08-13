#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        string ans = "" , temp = "" ;
        for(int i =S.length() -1 ;i >= 0 ; i--) {
            if(S[i] != '.') {
                temp += S[i] ;
            }
            else{
                reverse(temp.begin() , temp.end()) ;
                ans += temp ; ans += "." ;
                temp = "" ;
            }
        }
        reverse(temp.begin() , temp.end()) ;
        ans += temp ;
        return ans ;
    } 
};