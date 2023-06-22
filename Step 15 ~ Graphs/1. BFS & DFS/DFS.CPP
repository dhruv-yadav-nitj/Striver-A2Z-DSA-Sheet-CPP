#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void recursion (vector<int> adj[] , int node , vector<int>&isVisited , vector<int> &dfs){
        
        isVisited[node] = 1 ; dfs.push_back(node) ;
        for(auto it : adj[node]){
            if(!isVisited[it]){
                recursion(adj , it , isVisited , dfs) ;
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        // Code here

        vector<int> dfs , isVisited (V, 0) ;
        recursion(adj, 0, isVisited , dfs) ;
        return dfs ;
    }
};