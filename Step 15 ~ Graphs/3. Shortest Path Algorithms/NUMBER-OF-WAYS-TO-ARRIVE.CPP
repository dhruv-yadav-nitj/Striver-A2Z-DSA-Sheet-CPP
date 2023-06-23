#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countPaths(int n, vector<vector<int>> &roads){
        // code here

        // create a graph out of the given problem
        vector<pair<int, int>> adj[n] ;
        for(auto it: roads) {
            int u = it[0] , v = it[1] , wt = it[2] ;
            adj[u].push_back({v , wt}) ; adj[v].push_back({u , wt}) ;
            // since the roads are bidirectional they would form undirected graph
        }

        vector<int> time (n , 1e9) ; // distance array for djiktra algo
        vector<int> ways (n, 0) ; // this would store the number of ways in which we can reach a node

        priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq ;

        time[0] = 0 ;
        pq.push({0, 0}) ; ways[0] = 1 ; // it would take 0 time to read 0 from 0 and it makes the no of ways to reach 0 to 1

        while(!pq.empty()) {
            auto it = pq.top() ; pq.pop() ;
            int T = it.first , node = it.second ;

            for(auto it : adj[node]) {
                
                int v = it.first , wt = it.second;
                int newT = T + wt ;

                if(newT < time[v]) {
                    time[v] = newT ; ways[v] = ways[node] ;
                    // if we can reach a node in less time that it was possible earlier than why not reach the node from this path only
                    // so it would make no. of ways to reach this particular node equal to the no of ways it is possible to reach the prev node from where it is coming

                    pq.push({newT , v}) ;
                }
                else if(newT== time[v]) {
                    // if two paths take the same time to reach v --> so the min time to reach v remains the same only no. of ways to reach v would increase 
                    ways[v] += ways[node] ;
                }
            }
        }

        return ways[n-1] ;
    }
};

// this problem may give errors on gfg due to some large values.. though the concept is correct and same