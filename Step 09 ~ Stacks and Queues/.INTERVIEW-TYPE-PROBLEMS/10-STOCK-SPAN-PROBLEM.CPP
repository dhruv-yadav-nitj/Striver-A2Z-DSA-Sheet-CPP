#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

// Approach : prev greater element
// Do some dry run and u will understand

class Solution {
public:
    vector<int> calculateSpan(int price[], int n) {

        stack<int> st ; vector<int> ans ;
        for(int i =0; i < n ; i++) {

            while(!st.empty() and price[st.top()] <= price[i]) {
                st.pop() ;
            }
            if(st.empty()) {
                ans.push_back(i - (-1)) ;
            }
            else{
                ans.push_back(i - st.top()) ;
            }
            st.push(i) ;
        }
        return ans ;      
    }
};