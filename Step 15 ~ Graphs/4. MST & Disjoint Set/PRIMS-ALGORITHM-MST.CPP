#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here

        // requirements for MST
        int mst= 0 ; vector<int> isVisited (V, 0);
        priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;

        // start from the node 0
        pq.push({0 , 0}) ;

        while(!pq.empty()) {

            int node = pq.top().second , wt= pq.top().first ;
            pq.pop() ;

            if(!isVisited[node]) {
                // since we dont want to visit a node again and again so visit this node and its neighbours only if its unvisited
                isVisited[node]= 1 ; mst += wt ;

                for(auto it: adj[node]) {
                    int v = it[0] , edgeWt = it[1] ;
                    if(!isVisited[v]) {
                        pq.push({edgeWt , v}) ;
                    }
                }
            }
        }

        return mst ;
    }
};

// min heap is itself a very intelligent data structure ,its property of keeping the smallest element at top is very useful in building mst
// since the node with smallest edge weight would be always at the top so there's no chance that we end up taking any wrong edge ever (edge with greater wt than already available b/w two nodes)