#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuter(string &s) {
        // code here
        stack<char> st ; string ans = "" ;
        for(int i =0 ; i < s.length(); i++) {
            if(s[i] == '('){
                if(st.empty()) {
                    st.push('(') ;
                }
                else{
                    st.push('(') ; ans += "(" ;
                }
            }
            else{
                if(st.size() > 1) {
                    ans += ")" ;
                    st.pop() ;
                }
                else{
                    if(!st.empty())  {
                        st.pop() ;
                    }
                }
            }
        }
        return ans ;

    }
};