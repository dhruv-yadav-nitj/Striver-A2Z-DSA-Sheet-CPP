#include <bits/stdc++.h>
using namespace std;

// Approach #1 : Brute Force
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // code here
        
        // approach #1 : brute force -> assume each rectangle to be the starting point of the largest area and calculate the max area we can cover -> move to the left until u dont encounter any histogram of height smaller than the current histogram and same in the right

        // so basically we are searching for an index i such that height[i] < curr element in both the directions left and right

        int ans = 0 , n = heights.size() ;
        for(int i =0 ; i < n ; i++) {
            int temp = heights[i] ;

            // left subpart
            for(int k = i -1; k >= 0 ;k--) {
                if(heights[k] >= heights[i]) {
                    temp += heights[i] ;
                }
                else{
                    break ;
                }
            }

            // right subpart
            for(int j = i +1 ; j < n ; j++) {
                if(heights[j] >= heights[i]) {
                    temp += heights[i] ;
                }
                else{
                    break ;
                }
            }
            ans = max(ans, temp) ;
        }

        return ans ;
    }
};

// Approach #2 : 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // code here
        int n = heights.size() ;
        vector<int> leftSmaller (n) , rightSmaller (n) ;
        stack<int> st ;
        // calculating the leftSmaller element for each element
        for(int i = 0; i < n ; i++) {
            while(!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop() ;
            }
            if(st.empty()) {
                leftSmaller[i] = 0 ;
            }
            else{
                leftSmaller[i] = st.top() +1 ;
            }
            st.push(i) ;
        }
        while(!st.empty()) {st.pop() ;}

        for(int i = n -1 ; i >= 0 ; i--)  {
            while(!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop() ;
            }
            if(st.empty()){
                rightSmaller[i] = n +1 ;
            }
            else{
                rightSmaller[i] = st.top() +1 ;
            }
            st.push(i) ;
        }

        int ans = 0 ;
        for(int i =0 ; i < n ; i++ ){
            int curr = (rightSmaller[i] - 1 - leftSmaller[i]) * heights[i] ;
            ans = max(ans, curr) ;
        }
        return ans ;
        
    }
};

// Approach #3 : Optimised
class Solution {
public:
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
};