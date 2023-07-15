#include <bits/stdc++.h>
using namespace std;

// approach : point is to calculate the max number of active open brackets at a time

class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int curr = 0 , res= 0 ;
        for(int i =0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                curr++ ;
            }
            else if(s[i]==')') {
                curr--;
            }
            res= max(res, curr) ;
        }
        return res ;
    }
};