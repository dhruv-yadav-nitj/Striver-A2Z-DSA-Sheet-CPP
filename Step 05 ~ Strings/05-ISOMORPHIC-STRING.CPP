#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
        // Your code here
        unordered_map<char, char> mp ;
        if(str1.length() != str2.length()) {return false ;}
        int n = str1.length() ;
        for(int i =0 ; i < n ; i++) {
            if(!mp.count(str1[i])) {
                mp[str1[i]] = str2[i] ;
            }
            else{
                if(mp[str1[i]] != str2[i]) {
                    return false ;
                }
            }
        }

        unordered_map<char, char> mp2 ;
        for(int i =0 ; i < n ; i++) {
            if(!mp2.count(str2[i])) {
                mp2[str2[i]] = str1[i] ;
            }
            else{
                if(mp2[str2[i]] != str1[i]) {
                    return false ;
                }
            }
        }

        return true ;
    }
};