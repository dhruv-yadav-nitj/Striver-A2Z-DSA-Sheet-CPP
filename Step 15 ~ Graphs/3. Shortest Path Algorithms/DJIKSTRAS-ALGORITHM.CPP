// this algorithm can be used to find the shortest path to a node from source node in every graph (either its directed or undirected, cycle or acyclic) there except those graphs which have negative edge weights (use bellman ford algo for such graphs) ... bcz in graphs with negative edge weights it goes into infinite loop when priority queue is applied

// normal queue and even set can be also applied to implement Djikstra's Algorithm
// but using Priority Queue is more efficient

// Djikstra's Shortest Path Algorithm using Priority Queue
// Time ~ O(ElogV)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here

        priority_queue<pair<int, int> , vector<pair<int,int>> , greater <pair<int, int>>> pq ; // min-heap

        vector<int> distance (V , 1e9) ;
        distance[S] =0 ; pq.push({0, S}) ; // {dist , node} ; shortest distance of source from source is always 0

        while(!pq.empty()) {
            int dis=  pq.top().first , node = pq.top().second ; pq.pop() ;

            for(auto it : adj[node]) {
                int v = it[0] , wt = it[1] ;
                int newDis = dis + wt ;
                if(newDis < distance[v]) {
                    distance[v] = newDis;
                    pq.push({newDis , v}) ;
                }
            }
        }

        // in the given problem the graph given is always a connected one so there is no node where we cant reach from the src
        return distance ;
    }
};