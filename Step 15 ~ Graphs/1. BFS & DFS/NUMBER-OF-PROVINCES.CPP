#include <bits/stdc++.h>
using namespace std;


// approach #1  : using simple dfs
class Solution{
public:
    void dfs (vector<int> adj[] , vector<int>&isVisited , int node){
        isVisited[node] = 1 ; // mark this node as visited

        for(auto it: adj[node]){
            if(!isVisited[it]){
                dfs(adj , isVisited , it) ;
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V){
        // code here
        vector<int> isVisited (V+1, 0) ;
        vector<int> adjList[V+1] ; int count =0 ;
        
        // creating a adjacency list for the convenience
        for(int i = 0;i < V ; i++){
            for(int j = 0; j < V ; j++){
                if(i != j and adj[i][j] == 1){
                    adjList[i+1].push_back(j+1) ;
                    adjList[j+1].push_back(i+1) ;
                }
            }
        }

        for(int i =1 ; i <= V ;i++){
            if(!isVisited[i]){
                // dfs and bfs always traverse all the nodes that are connected so we would use this property
                // call for dfs and in that dfs we would travel and mark all the nodes as visited which is connected to this unvisited node
                // so the number of province would be equal to the number of times this dfs call is applied
                count++ ;
                dfs(adjList , isVisited , i) ;
            }
        }

        return count ;

    }
};