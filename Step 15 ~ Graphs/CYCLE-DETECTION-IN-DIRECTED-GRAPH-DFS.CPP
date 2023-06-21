// cycle detection in directed graph using dfs
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool dfs (vector<int> adj[], int node , vector<int>&isVisited ,vector<int>&samePath){
        // mark the node as visited and also mark that node in the samePath
        isVisited[node] = 1 ; samePath[node]= 1 ;
        for(auto x : adj[node]){
            
            // if the adjacent is already visited and also lie in the same path means cycle is present
            if(isVisited[x] and samePath[x]){
                return 1 ;
            }

            // if the adjacent node is not visited
            if(!isVisited[x]){

                if(dfs(adj , x , isVisited , samePath)){
                    return true ;
                }
            }
        }

        // when the call is complete then remove that this node was in the path
        samePath[node]=  0;
        return false ;

    }
    bool isCyclic(int V, vector<int> adj[]){
        // code here

        vector<int> isVisited (V, 0) ; vector<int> samePath (V, 0) ;

        for(int i = 0 ; i < V; i++){
            if(!isVisited[i]){
                if(dfs(adj , i , isVisited , samePath)) {
                    return true ;
                }
            }
        }

        return false;
    }
};