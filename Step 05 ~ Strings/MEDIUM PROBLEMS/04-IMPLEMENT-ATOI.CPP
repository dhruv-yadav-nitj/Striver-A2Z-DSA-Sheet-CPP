#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/implement-atoi/1

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0 ; int i = 0; bool flag= false ;
        if(str[i] == '-') {
            flag= true ;
            i++ ;
        }
        
        for( ; i < str.length() ; i++) {
            if(str[i] >= '0' and str[i] <= '9') {
                int curr = str[i] - '0' ;
                ans = ans * 10 + curr ; 
            }
            else{
                return -1 ;
            }
            
        }
        if(flag) {
            return -ans ;
        }
        return ans ;
    }
};