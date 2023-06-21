#include <bits/stdc++.h>
using namespace std;

// applying kahn's algorithm
// exactly topo sort just wordings are different

class Solution{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites){
        // code here
        
        // creating a graph according to the given data
        vector<int> adj[n] ; // 0-based graph
        vector<int> indegree (n , 0) ;
        for(auto it : prerequisites){
            int u = it[1] , v = it[0] ;
            adj[u].push_back(v) ; indegree[v]++ ;
        }

        queue<int> q ;
        vector<int> order ; // topo sort
        for(int i =0; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        while(!q.empty()) {
            int node = q.front() ; q.pop() ;
            order.push_back(node) ;

            for(auto it : adj[node]) {
                indegree[it]-- ;
                if(indegree[it] ==0) {
                    q.push(it) ;
                }
            }
        }

        if(order.size() == n){
            return order ;
        }
        else{
            return {} ;
        }

    }
};