#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs (vector<int> adj[] , vector<int>&isVisited , int  node , stack<int>&st){
        isVisited[node] = 1;

        for(auto it : adj[node]){
            if(!isVisited[it]){
                dfs(adj , isVisited, it , st) ;
            }
        }

        st.push(node) ;

    }
    vector<int> topoSort(int V, vector<int> adj[]){
        // code here

        // requirements
        vector<int> isVisited (V , 0) ; stack<int> st ;
        for(int i =0 ; i < V ; i++){
            if(!isVisited[i]) {
                dfs(adj , isVisited , i, st) ;
            }
        }

        vector<int> ans ;
        while(!st.empty()){
            ans.push_back(st.top()) ; st.pop() ;
        }

        return ans ;
    }
};