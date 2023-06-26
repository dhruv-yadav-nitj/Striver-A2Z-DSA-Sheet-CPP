#include <bits/stdc++.h>
using namespace std;

// Tarjan Algorithm

// this ques is kinda algorithms based (k/a Tarzan Algorithm) -> understanding of this algo was tough for me -> revise properly
// two types of ques -> print all the bridges or return if a given egde is a bridge or not

// if you dont understand this problem -> then go and watch the striver's video bcz thats the best way one can teach you this problem and the example taken by striver in the video was also very perfect

class Solution{
public:
    // Function to find if the given edge is a bridge in graph.
    void tarjanAlgo (vector<int> adj[] , int node , int parent, int&timer , vector<int>&isVisited, vector<int>&low, vector<int>&time, set<vector<int>>&bridges) {
        // based on dfs

        isVisited[node]= 1 ; time[node] = low[node] = timer ; ++timer; 

        for(auto it : adj[node]) {
            if(it != parent) {

                if(!isVisited[it]) {
                    tarjanAlgo(adj , it , node , timer, isVisited , low , time, bridges) ;
                    
                    // if low[it] > time[node] -> this means there's in only one way to travel to 'it' which is through 'node' so this can be a bridge
                    if(low[it] > time[node]) {
                        bridges.insert({node, it}) ;
                    }
                    
                    // update the low of node
                    low[node] = min (low[it] , low[node]) ;
                }
                else{
                    // if its already visited -> just update the low of node
                    low[node] = min(low[it] , low[node]) ;
                }
            }
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d){
        // Code here

        vector<int> isVisited (V, 0) , low (V) , time(V) ;
        int timer (0) ; // keeps track of the current time

        set<vector<int>> ans ; // this would store all the bridges

        // since the graph may consist of components which are not connected to each other
        for(int i =0 ; i < V ; i++){
            if(!isVisited[i]) {
                tarjanAlgo(adj , i , -1 , timer,  isVisited , low , time, ans) ; 
            }
        }
        
        if(ans.count({c, d}) or ans.count({d, c})){
            return 1 ;
        }
        else{
            return 0 ;
        }

    }
};