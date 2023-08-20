#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximal-rectangle/description/
// Simply a follow up question of prev problem

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st ; int ans (0); int n = heights.size() ;
        for(int i=0; i<= n; i++) {
            while(!st.empty() and (i == n or heights[st.top()] >= heights[i])) {
                int h = heights[st.top()] ; st.pop() ;
                int width;
                if(st.empty()) {width = i ;}
                else{
                    width = i - st.top() -1 ;
                }
                ans = max(ans, width*h) ;
            }
            st.push(i) ;
        }
        return ans ;        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<vector<int>> heights ; int n= matrix.size() , m = matrix[0].size() ;
        for(int i =0; i < n ; i++) {

            vector<int> curr ; 
            if(i ==0){
                for(auto it : matrix[i]){
                    curr.push_back(it - '0') ;
                }
                heights.push_back(curr);
                continue ;
            }

            for(int j =0 ; j < m ; j++) {
                if(matrix[i][j]=='0'){curr.push_back(0);}
                else{
                    curr.push_back(1+heights[i-1][j]) ;
                }
            }
            heights.push_back(curr) ;
        }
        
        int ans =0;
        for(int i =0 ; i < n ; i++) {
            ans = max(ans, largestRectangleArea(heights[i]));
        }
        return ans ;        
    }
};