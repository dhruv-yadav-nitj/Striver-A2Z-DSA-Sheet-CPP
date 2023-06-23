#include <bits/stdc++.h>
using namespace std;

// very basic question on djikstra's algorithm

class Solution{
public:
    int minimumCost(vector<vector<int>> &flights, int n, int k){
        // code here
        
        // step 1 : making a graph out of the given data
        vector<pair<int, int>> adj[n +1] ; // graph would be 1-indexed

        for(auto it : flights) {
            int u = it[0] , v = it[1] , wt = it[2] ;
            adj[u].push_back({v, wt}) ;
        }

        vector<int> cost (n + 1 , 1e9) ; // distance array for djikstra's algorithm
        cost[k] = 0 ; // jha se flight start hogi wha ka cost to zero hi hoga
        priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq ;
        pq.push({0 , k}) ;

        while(!pq.empty()) {
            int currCost = pq.top().first , node = pq.top().second ; pq.pop() ;

            for(auto x : adj[node]) {
                int v = x.first ,wt= x.second , newCost = currCost + wt ;
                if(newCost < cost[v]) {
                    cost[v] = newCost;
                    pq.push({newCost , v}) ;
                }
            }
        }
        
        int maxi = INT_MIN ;
        
        for(int i=1 ;i <= n ; i++){
            if(cost[i] == 1e9) {
                return -1 ;
            }
            else{
                maxi = max(maxi , cost[i]) ;
            }
        }

        return maxi ;
    }
};