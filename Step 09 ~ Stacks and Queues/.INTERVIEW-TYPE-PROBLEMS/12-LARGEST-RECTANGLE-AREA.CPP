#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Approach : Simply search for immediate smaller element towards the left and towards the right

// Algorithm 1
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {

        int ans (0) ; int n = heights.size() ;
        for(int i =0; i < n ; i++) {

            // checking next left smaller element
            int l = i , r = i;
            while(l >=0 and heights[l] >= heights[i]) {
                l-- ;
            }
            while(r < n and heights[r] >= heights[i]) {
                r++ ;
            }
            int width = r - l -1 ; ans = max(ans, width * heights[i]) ;
        }
        return ans ;
    }
};

// Algorithm 2
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st1, st2 ; int n = heights.size() ;
        vector<int> left (n), right(n) ;

        for(int i =0; i < n ; i++) {
            while(!st1.empty() and heights[st1.top()] >= heights[i]) {
                st1.pop() ;
            }
            if(st1.empty()){
                left[i]=-1 ;
            }
            else{left[i]=st1.top();}
            st1.push(i) ;
        }
        
        for(int i = n-1; i >= 0 ; i--) {

            while(!st2.empty() and heights[st2.top()]>=heights[i]){st2.pop() ;}
            if(st2.empty()) {right[i]=n ;}
            else{
                right[i]=st2.top() ;
            }
            st2.push(i) ;
        }

        int ans (0) ;
        for(int i =0 ; i < n ; i++) {
            int width = right[i] - left[i] -1 ;
            ans = max(ans, width * heights[i]) ;
        }
        return ans ;        
    }
};

// Approach 3
// Note: Striver clearly said, if this type of ques. is asked in the interview then stop at the previous solution, because they were more intuitive. Tell this solution iff the interviewer asked to more optimise the previous solution.
// There is only one way to understand this approach : Do dry run. Take heights[i] = 3, 2, 10, 11, 5, 10, 6, 7
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
};

// Simply we have to play using left and right smaller, if stack is empty -> no choice, just push into the stack ; if stack is not empty -> check if st.top() is larger or smaller -> if st.top() is larger than current element than we can say that current element must be next smaller element of the current top element of stack -> so now we must find the area occupied by st.top() whose right smaller is current element and left smaller is the element just below the st.top() ; else if st.top() is smaller than the current element then we must push the current element into the stack since we not only need the left smaller element but also the right smaller element -> so in this case just push the current element into stack and move on.