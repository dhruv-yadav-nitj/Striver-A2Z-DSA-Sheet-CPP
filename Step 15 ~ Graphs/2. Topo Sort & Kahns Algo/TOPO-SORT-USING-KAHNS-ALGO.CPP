#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        // code here

        // kahn's algo 

        // requirements
        vector<int> indegree (V, 0); // initially every node has indegree as 0
        queue<int> q ;

        for(int i=0; i < V ; i++){
            for(auto it : adj[i]) {
                indegree[it]++ ;
            }
        }

        vector<int> topo ;

        for(int i =0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i) ; // those processes which do not depend on any other processes they must be inserted in the queue
            }
        }

        while(!q.empty()){
            int node = q.front() ; q.pop() ;
            topo.push_back(node) ;

            for(auto it : adj[node]) {
                indegree[it]-- ;
                if(indegree[it] ==0){
                    q.push(it) ;
                }
            }
        }

        return topo ;

    }
};