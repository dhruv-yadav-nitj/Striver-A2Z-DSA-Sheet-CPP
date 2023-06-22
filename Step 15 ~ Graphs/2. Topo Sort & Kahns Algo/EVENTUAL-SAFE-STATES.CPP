#include <bits/stdc++.h>
using namespace std;

// a good applicational problem of topp sort
// this ques tell us how in different ways can we think to solve a problem based on topo sort

// every node leads to a terminal node until the node is a part of cycle in the graph

class Solution{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adjo[]){
        // code here

        // make a new graph with reverse edges
        vector<int> adj[V] ; vector<int> indegree (V, 0) ;
        for(int i =0;i < V ; i++){
            for(auto it : adjo[i]) {
                adj[it].push_back(i) ;
                indegree[i]++ ;
            }
        }

        // now just simply apply kahn's algorithm
        vector<int> kahn ; queue<int> q ;
        for(int i =0; i < V ; i++){
            if(indegree[i]==0) {
                q.push(i) ;
            }
        }

        while(!q.empty()) {
            int node = q.front() ; q.pop() ;
            kahn.push_back(node) ;
            for(auto it : adj[node]){
                indegree[it]-- ;
                if(indegree[it] ==0){
                    q.push(it) ;
                }
            }
        }

        // ans needs to be in sorted format acc to the problem
        sort(kahn.begin() , kahn.end()) ;
        return kahn ;

    }
};