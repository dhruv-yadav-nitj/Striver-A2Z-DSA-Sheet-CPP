#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// https://leetcode.com/problems/find-the-town-judge/

// BRUTE FORCE ~ O(N^2)

// OPTIMISED ~ O(N)
// Explanation : https://youtu.be/CiiXBvrX-5A (just listen to his initial 2-3 mins and u will understand the approach)

// we would apply ELIMINATION OF NON-POSSIBLE ANSWERS TECHNIQUE (which we used to do during JEE in MCQ type questions)

class Solution {
public:
    int celebrity(vector<vector<int>> &M, int n) {

        stack<int> st ;
        for(int i=0; i < n ; i++) {st.push(i) ;}

        while(!st.empty() and st.size() > 1) {
            int a=st.top();st.pop() ; int b= st.top(); st.pop() ;
            if(M[a][b]==1) {
                // means a knows b -> then for sure a is not the celebrity
                st.push(b) ; continue;
            }
            else if(M[b][a]==1){
                st.push(a) ; continue;
            }
        }

        if(st.empty()) {return -1 ;}
        else{

            int poss = st.top() ;
            // check if poss knows no one
            for(int i = 0 ; i < n ; i++) {
                if(M[poss][i]==1){
                    return -1 ;
                }
            }
            // check if every one knows poss
            for(int i=0;i  < n ; i++) {
                if(i != poss) {
                    if(M[i][poss]==0){
                        return -1 ;
                    }
                }
            }
            return st.top() ;
        }
    }
};