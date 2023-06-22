#include <bits/stdc++.h>
using namespace std;

// a graph is known as bipartite graph if we can color all the nodes using two color only such that any two adjacent nodes are not of same color

// similar ques M-Coloring Problem (based on Recursion)

class Solution{
public:
    bool dfs (vector<int> adj[] , int node , int color, vector<int>&isVisited, vector<int>&store){
        isVisited[node] = 1 ; store[node] = color ;

        for(auto x : adj[node]){
            if(!isVisited[x]){
                if(!dfs(adj , x , !color, isVisited, store)){
                    return false ;
                }
            }
            else{
                if(store[x] == color){
                    return false ;
                }
            }
        }

        return true ;

    }
    bool isBipartite(int V, vector<int> adj[]){
        // Code here

        vector<int> isVisited (V, 0) ; vector<int> store (V ,-1) ;
        for(int i = 0 ;i < V ; i++){
            if(!isVisited[i]) {
                if(!dfs(adj , i , 1, isVisited , store)){
                    return false ;
                }
            }
        }

        return true ;

    }
};