#include <bits/stdc++.h>
using namespace std;

// just simple basic intuition

class Solution{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges){
        // code here

        vector<pair<int, int>> adj[N] ;
        for(auto it : edges){
            int u = it[0] , v = it[1] , wt = it[2] ;
            adj[u].push_back ({v, wt}) ;
        }

        queue <pair<int, int>> q ; vector<int> distance (N , 1e9) ;
        int src =0 ; q.push({src ,0}) ; distance[src] = 0 ;

        while(!q.empty()) {
            int node = q.front().first , dis = q.front().second ;
            q.pop() ;

            for(auto it : adj[node]) {
                int v = it.first , wt = it.second ;
                int newDist= dis+ wt; 
                if(newDist < distance[v]) {
                    distance[v]= newDist ; q.push({v, newDist}) ;
                }
            }
        }

        vector<int> res (N, -1) ;
        for(int i =0; i < N ; i++){
            if(distance[i] != 1e9) {
                res[i] = distance[i] ;
            }
        }

        return res ;
    }
};