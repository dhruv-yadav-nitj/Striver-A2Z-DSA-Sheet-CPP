#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    void insert (stack<int>&st , int x) {
        if(st.empty()){
            st.push(x) ; return ;
        }

        int top = st.top() ; st.pop() ;
        insert(st, x) ;

        st.push(top) ;

    }
    void Reverse(stack<int> &St){
        
        if(St.empty()){
            return ;
        }

        int top = St.top() ; St.pop() ;
        Reverse(St) ;

        insert (St , top) ;
    }
};