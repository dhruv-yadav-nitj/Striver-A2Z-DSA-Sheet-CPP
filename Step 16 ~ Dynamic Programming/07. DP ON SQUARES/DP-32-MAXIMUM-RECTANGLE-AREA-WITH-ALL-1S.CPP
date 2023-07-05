#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// Largest Rectangle Area in Histogram Explanation
// https://youtu.be/X0X6G-eWgQ8
// https://youtu.be/jC_cWLy7jSI

class Solution {
public:
    // pre-required function from MAX Rectangle Area in histogram problem
    int largestRectangleArea(vector<int>& heights) {
        // code here
        stack<int> st ; int n = heights.size() , ans = 0 ;
        for(int i =0 ; i <= n ; i++) {
            while(!st.empty() and (i==n or heights[st.top()] >= heights[i])) {
                // means jo st.top() tha ab uska area calculate krna hain 
                // uska right boundary i ho jaaega aur left boundary hoga jo 2nd number pr hain stack mein

                int height = heights[st.top()] ; st.pop() ; int width ;
                if(st.empty()) {
                    width = i ;
                }
                else{
                    width = i - st.top() -1 ;
                }
                ans = max(ans , (height * width)) ;
            }
            st.push(i) ;
        }

        return ans ;
        
    }

    // just treat each row as a base to Histogram

    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<vector<int>> dp (n+1 , vector<int> (m , 0)) ;
        for(int i =1 ; i <= n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(M[i-1][j] == 1) {
                    dp[i][j] = dp[i-1][j] + 1 ;
                }
            }
        }

        int ans = 0 ;
        for(auto it : dp) {
            ans = max (ans , largestRectangleArea(it)) ;
        }

        return ans ;

    }
};