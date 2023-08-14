#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

/* 
Intuition : 
    <very intuitive approach> <anyone can think it at any time>
    instead of using stack<int> we would be using stack<pair<int,int>> where for the first element would be the actual number and second number of the pair would be the minimum element till now (which would be updated every time we insert some new element by comparing it with the current number)
*/

class Solution {
    int minEle; stack<pair<int, int>> st;
public:
    /*returns min element from stack*/
    int getMin() {
        if (st.empty()) {
            return -1;
        }
        else {
            return st.top().second;
        }
    }

    /*returns poped element from stack*/
    int pop(){
        if (st.empty()) {
            return -1;
        }
        else {
            int ans = st.top().first;st.pop();return ans;
        }
    }

    /*push element x into the stack*/
    void push(int x) {
        if (st.empty()) {
            st.push({x,x,}); return;
        }
        int mini = min(st.top().second, x);
        st.push({x, mini});
    }
};