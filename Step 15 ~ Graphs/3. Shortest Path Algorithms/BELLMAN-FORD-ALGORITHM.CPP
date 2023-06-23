#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S){
        // Code here

        // so the edges can be given in any order --> the order of edge has no effect on this algorithm --> so we need not make any adj list

        vector<int> distance (V , 1e8) ;
        distance[S] = 0 ;

        // relaxing V-1 times            
        for(int i=0 ; i < V ; i++) {
            
            for(auto it: edges) {
                
                int u = it[0] , v = it[1] , wt= it[2] ;
                if(distance[u]!= 1e8) {
                    int dis = distance[u] + wt ;
                    if(dis < distance[v]){
                        distance[v] = dis ;
                    }
                }
            }
        }

        // relaxing one more time to detect negative cycle
        for(auto it : edges) {
            int u = it[0] , v = it[1] , wt=it[2] ;
            int dis = distance[u] + wt ;
            if(dis < distance[v]) {
                return {-1} ;
            }
        }

        return distance ;

    }
};