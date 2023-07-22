#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

class Solution {
public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // CODE HERE
        unordered_set<int> st ; priority_queue<int, vector<int>, greater<int>> pq ;
        for(auto it: arr) {
            if(!st.count(it)) {
                st.insert(it) ; pq.push(it) ;
            }
        }
        
        int cnt =1 ; unordered_map<int, int> mp;
        while(!pq.empty()) {
            mp[pq.top()] = cnt++ ; pq.pop() ;
        }

        for(int i= 0; i < N ; i++) {
            arr[i] = mp[arr[i]] ;
        }

        return arr ;

    }
};

// can be also done without using priority queues and only using maps
class Solution {
public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // CODE HERE
        unordered_map<int,int> mp ;
        vector<int> temp = arr ; sort(temp.begin() , temp.end()) ; int cnt =1 ;
        for(int i =0 ;i < N ; i++) {
            if(!mp.count(temp[i])) {
                mp[temp[i]] = cnt++ ;
            }
        }

        for(int i =0 ; i < N ; i++) {
            arr[i] = mp[arr[i]] ;
        }

        return arr ;

    }
};