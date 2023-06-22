#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        // Code here

        // given the graph in the form of adjacency list
        queue<int> q ; vector<int> bfs ; vector<int> isVisited (V, 0) ;
        q.push(0) ; isVisited[0] = 1 ;
        while(!q.empty()){
            int x = q.front() ; q.pop() ;
            bfs.push_back(x) ;

            for(auto it : adj[x]){
                if(!isVisited[it]){
                    q.push(it) ;
                    isVisited[it] = 1 ;
                }
            }
        }

        return bfs ;

    }
};