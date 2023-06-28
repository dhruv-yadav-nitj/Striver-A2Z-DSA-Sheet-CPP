#include <bits/stdc++.h>
using namespace std;

/* 
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
*/

class Solution{
public:
    bool ispar(string x){
        // Your code here

        stack<char> st ;
        for(auto it : x) {
            if(!st.empty() and it == ')' and st.top() == '('){
                st.pop() ;
            }
            else if(!st.empty() and it == '}' and st.top() == '{'){
                st.pop() ;
            }
            else if(!st.empty() and it == ']' and st.top() == '['){
                st.pop() ;
            }
            else{
                st.push(it) ;
            }
        }

        return st.empty() ;

    }
};