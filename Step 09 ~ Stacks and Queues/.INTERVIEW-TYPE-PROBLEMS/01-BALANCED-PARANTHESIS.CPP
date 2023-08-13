#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {

        if(s.length() ==0){
            return true ;
        }

        stack<char> st ;
        for(auto it : s) {

            if(it == '(' or it == '{' or it == '[') {
                st.push(it) ;
            }

            else if (it == ')') {
                if(!st.empty() and st.top() == '('){
                    st.pop() ;
                }
                else{
                    return false ;
                }
            }

            else if (it == '}') {
                if(!st.empty() and st.top() == '{'){
                    st.pop() ;
                }
                else{
                    return false ;
                }
            }

            else if (it == ']') {
                if(!st.empty() and st.top() == '['){
                    st.pop() ;
                }
                else{
                    return false ;
                }
            }
        }
        return st.empty() ;
    }
};