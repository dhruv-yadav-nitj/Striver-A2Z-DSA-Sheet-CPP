#include <bits/stdc++.h>
using namespace std ;

// the edge weights are given to be unity

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here

        // requirements
        vector<int> adj[N] ;
        for(auto it : edges) {
            int u = it[0] , v = it[1] ;
            adj[u].push_back(v) ; adj[v].push_back(u) ; // undirected graph
        }

        vector<int> distance (N , 1e9) ; // distance array would store the min distance of node[i] from src , initially all the value are some greater value
        queue<pair<int, int>> q ;
        q.push({src , 0}) ; distance[src]= 0 ;
        
        while(!q.empty()) {
            int node = q.front().first , dis = q.front().second ; q.pop() ;

            for(auto it : adj[node]) {
                if(dis + 1 < distance[it]) {
                    distance[it] = dis + 1; q.push({it , distance[it]}) ;
                }
            }
        }

        vector<int> res (N , 0) ;
        // since there may be such nodes which are un reachable from src
        for(int i =0 ; i < N ; i++){
            if(distance[i] != 1e9) {
                res[i] = distance[i] ;
            }
            else{
                res[i] = -1 ;
            }
        }

        return res ;
    }
};