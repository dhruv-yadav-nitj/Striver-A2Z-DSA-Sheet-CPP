#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

// just count the number of indexes where the string is rotated -> if the count <= 1 -> then its true else not

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length() != s2.length()) {
            return false ;
        }
        
        int n = s1.length() ;
        unordered_map<char,int> mp ;
        for(int i =0 ; i < n ; i++) {
            mp[s1[i]] = i ;
        }
        
        int count = 0;
        for(int i =0 ;i < n - 1; i++) {
            if(mp[s2[i+1]] != mp[s2[i]] + 1){
                count++ ;
            }
        }
        return (count <= 1) ;
    }
};