#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

class Solution {
public:
    static bool custom (const string a, const string b) {
        return a.length() < b.length() ;
    }
    string longestCommonPrefix(string arr[], int N) {
        // your code here
        sort(arr, arr + N , custom) ;

        string ans = arr[0] ;
        for(int i =1 ; i < N ; i++) {
            if(ans.length() > 0) {
                int k=0, j =0 ;
                while(k < ans.length() and j < ans.length()) {
                    if(arr[i][j] != ans[k]) {
                        ans.erase(ans.begin() +  k , ans.end()) ;
                        break ;
                    }
                    k++ , j++ ;
                }
            }
            else{
                return "-1" ;
            }
        }
        return ans ;        

    }
};