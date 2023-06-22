#include <bits/stdc++.h>
using namespace std;

// using bfs
class Solution{
public:
    bool isCycle(int V, vector<int> adj[]){
        // Code here
        
        // remember the graph can have multiple unconnected components (so we would be using for loop)
        queue<pair<int,int>> q ; vector<int> isVisited (V , 0) ; // 0 - index based graph
        // these two things are the atleast requirement before proceeding with bfs

        for(int i=0 ;i < V ; i++){

            if(!isVisited[i]){

                // starting point of a component of the graph
                q.push({i , -1}) ; // <child, parent>
                isVisited[i] = 1 ;

                while(!q.empty()){
                    int child = q.front().first , parent = q.front().second ;
                    q.pop() ;

                    for(auto x : adj[child]){
                        if(x != parent){
                            // why would we move back to parent node ever !
                            // we should not again move back to the parent node

                            if(!isVisited[x]){
                                q.push({x , child}) ; // current node would be the parent of its adjacent nodes
                                isVisited[x] = 1 ;
                            }
                            else{
                                // it means there's some adjacent node which is already visited (means there are two ways to reach the same node) --> cycle present
                                return true ;
                            }

                        }
                    }

                }

            }

        }
        return false ;

    }
};


// using dfs
class Solution{
public:
    bool dfs(vector<int> adj[], vector<int>&isVisited , int node, int parent){
        isVisited[node] = 1 ;

        for(auto x : adj[node]){

            // we woudl not consider parent node
            if(x != parent){

                // if its not the parent but still is already visited then return true
                if(isVisited[x]){
                    return true ;
                }
                else if(dfs(adj , isVisited , x , node)){
                    return true ;
                }
            }
        }

        return false ;

    }
    bool isCycle(int V, vector<int> adj[]){
        // Code here

        vector<int> isVisited (V , 0) ;
        for(int i =0; i < V ; i++){
            if(!isVisited[i]){
                if(dfs(adj, isVisited, i , -1)){
                    return true ;
                }
            }
        }

        return false ;

    }
};