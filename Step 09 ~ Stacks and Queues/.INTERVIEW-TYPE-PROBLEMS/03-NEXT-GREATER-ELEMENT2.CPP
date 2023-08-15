#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(int N, vector<int> &arr) {

        // Old Skool Trick for circular array : traverse twice

        stack<int> st ; vector<int> ans(N) ;
        for(int i = 2*N-1; i >=0; i--) {

            int k = i % N ;
            while(!st.empty() and st.top() <= arr[k]) {
                st.pop() ;
            }
            if(st.empty()) {
                ans[k] = -1 ; st.push(arr[k]) ;
            }
            else{
                ans[k] = st.top(); st.push(arr[k]) ;
            }
        }
        return ans ;
    }
};