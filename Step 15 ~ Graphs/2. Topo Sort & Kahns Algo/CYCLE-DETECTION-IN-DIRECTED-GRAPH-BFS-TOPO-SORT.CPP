#include <bits/stdc++.h>
using namespace std ;

// one very good property of topo sort is that it never consider cyclic parts of a graph --> so this property can be used to detect cycle in a directed graph
// topo sort the graph and if the size of topo vector at last is not equal to the given size of graph --> it means cycle is present
// this property is also very useful in solving HARD problems on topo sort (like Find Eventual Safe States)

class Solution {
  public:
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here

        int inDegree [V] = {0};
        for(int i =0;  i < V ;i++){
            for(auto x : adj[i]){
                inDegree[x]++ ;
            }
        }

        // now we have indegree wla array
        vector<int> topo ; queue<int> q ;
        for(int i =0; i < V ; i++){
            if(inDegree[i] == 0){q.push(i) ;}
        } // q mein hmare paas wo elements aa gye hain jinki indegree 0 rha hoga

        while(!q.empty()){
            int node = q.front() ; q.pop() ; topo.push_back(node) ;
            for(auto x : adj[node]){
                inDegree[x]-- ;
                if(inDegree[x] == 0){q.push(x) ;}
            }
        }

        return (topo.size() != V) ;

    }
    
};