#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n) {
        // code here
        bool buy = true ; int b , s ; vector<vector<int>> ans ;
        for(int i =0;i  < n ; i++) {
            if(buy and A[i] < A[i+1]) {
                b = i ; buy = false ;
            }
            else if(!buy and A[i] > A[i+1]) {
                s= i ; 
                ans.push_back({b, s}) ; buy = true ;
            }
        }
        // if the loop terminates and we still have some stocks to Sell 
        if(!buy and A[n-1] > A[b]) {
            ans.push_back({b, n-1}) ;
        }
        return ans;
    }
};