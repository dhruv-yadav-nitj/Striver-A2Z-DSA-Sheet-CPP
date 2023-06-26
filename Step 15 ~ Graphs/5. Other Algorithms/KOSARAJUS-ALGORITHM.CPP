#include <bits/stdc++.h>
using namespace std;

// Kosaraju's Algorithm -> two types of problems are asked : no. of SCC and print all SCC
// just remember the steps and it would be easy

class Solution{
public:
    // Function to find number of strongly connected components in the graph.
    void topoSort (vector<int>adj[] , int node , stack<int>&st , vector<int>&isVisited)  {
        isVisited[node] = 1 ;
        for(auto it : adj[node]) {
            if(!isVisited[it]) {
                topoSort(adj , it , st , isVisited) ;
            }
        }

        // push the node in the stack as soon as the call is finished
        st.push(node) ;
    }
    void dfs (vector<int>adj[] , int node , vector<int>&isVisited) {
        isVisited[node] = 1 ;
        for(auto it : adj[node]) {
            if(!isVisited[it]) {
                dfs(adj , it, isVisited) ;
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &matrix){
        // code here

        // make a adjacency list
        vector<int> adj[V] ;
        for(int i =0 ; i < V ; i++) {
            for(auto x : matrix[i]) {
                adj[i].push_back(x) ;
            }
        }

        // Step 1 : since we need nodes in the order of finishing time -> use topo sort
        vector<int> isVisited (V , 0) ;
        stack<int> st ;
        // the graph may consist of different components which are not at all connected to each other so a loop is used
        for(int i =0; i < V ; i++){
            if(!isVisited[i]){
                topoSort(adj, i , st, isVisited) ;
            }
        }


        // Step 2 : reverse the graph
        vector<int> adj2[V] ;
        for(int i =0 ;i < V ; i++) {
            for(auto x : adj[i]) {
                adj2[x].push_back(i) ;
            }   
        }

        // Step 3 : start traversing the nodes in the order of topoSort
        int count (0) ; vector<int> isVisited2(V, 0) ;
        while(!st.empty()) {
            int node = st.top() ; st.pop() ;
            if(!isVisited2[node]) {
                count++ ;
                dfs(adj2 , node , isVisited2) ;
            }
        }

        return count ;
    }
};