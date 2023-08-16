#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINKS
// https://leetcode.com/problems/asteroid-collision/
// https://practice.geeksforgeeks.org/problems/asteroid-collision/1

/* Intuition :
start from the right end
make all the possible cases for st.top() and upcoming numbers:
upcoming number, st.top() -> can be like these cases: 
+ve, -ve -> both will hit and number having larger mod will sustain
+ve, +ve -> none of them will hit -> simply insert into stack
-ve, -ve -> none of them will hit -> just insert into stack
-ve, +ve -> none of them will hit -> since dono apne apne raaste

conlusion:
if the st.empty() -> insert
if arr[i] < 0 -> simply insert
if arr[i] > 0 -> it will keep hitting until st.top() < 0 and st.top() < arr[i] -> after this there can be four more cases ->
if the st.empty() -> simply insert
if the st.top() is still negative but has magnitude greater than arr[i] -> arr[i] will finish
if the st.top() is still negative but has magnitude equal to arr[i] -> arr[i] and st.top() both will finish
if the st.top() is +ve -> simply insert
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {

        stack<int> st ; int n = asteroids.size() ;
        for(int i=n-1; i >=0; i--) {

            if(st.empty()) {
                st.push(asteroids[i]) ;
            }
            else{
                // arr[i] --> +ve
                if(asteroids[i] >= 0) {

                    if(st.top() >=0) {
                        st.push(asteroids[i]) ;
                        continue ;
                    }

                    while(!st.empty() and st.top() < 0 and abs(st.top()) < asteroids[i]) {
                        st.pop() ;
                    }
                    if(st.empty()) {st.push(asteroids[i]) ;}
                    else{
                        // matlab stack empty bhi nahi hain
                        if(st.top()<0 and abs(st.top()) == asteroids[i]){st.pop() ;}
                        else if(st.top() > 0) {
                            st.push(asteroids[i]) ;
                        }
                    }
                }
                // arr[i] --> -ve
                else{
                    st.push(asteroids[i]) ;
                }
            }
        }

        vector<int> ans ; while(!st.empty()) {ans.push_back(st.top()); st.pop() ;}
        return ans ;
    }
};