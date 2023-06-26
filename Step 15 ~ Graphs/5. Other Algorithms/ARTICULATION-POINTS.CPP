#include <bits/stdc++.h>
using namespace std;

// Pre-requisite : Bridge in Graph / Tarjan Algorithm

// vvv HARD problem -> both logically as well as implementation
// need to revise regularly to understand the logic

class Solution{
public:
    void tarjanAlgo (vector<int>adj[] , int node , vector<int>&mark ,vector<int>&isVisited , int parent , int &timer, vector<int>&low , vector<int>&time) {
        isVisited[node] = 1 ; time[node] = low[node] = timer ; ++timer ;

        int child= 0 ;
        for(auto it : adj[node]) {
            if(it!= parent) {

                if(!isVisited[it]) {
                    tarjanAlgo(adj , it , mark, isVisited, node , timer, low, time);
                    low[node] = min(low[node] , low[it]) ;
                    if(low[it] >= time[node] and parent != -1){
                        mark[node]= 1 ;
                    }
                    child++ ;
                }
                else{
                    low[node] =min(low[node], time[it]) ;
                }

            }
        }

        if(child > 1 and parent== -1){
            mark[node] = 1 ;
        }

    }
    vector<int> articulationPoints(int V, vector<int> adj[]){
        // Code here

        vector<int> low (V) , time(V) , mark(V, 0) , isVisited (V,0) ;
        int timer = 1 ;
        for(int i=0 ; i < V ; i++){
            if(!isVisited[i]){
                tarjanAlgo(adj , i,  mark, isVisited, -1 , timer, low, time) ;
            }
        }

        vector<int> ans ;
        for(int i =0; i< V; i++){
            if(mark[i]) {
                ans.push_back(i) ;
            }
        }

        if(ans.size() == 0) {
            return {-1} ;
        }

        return ans ;
    }
};