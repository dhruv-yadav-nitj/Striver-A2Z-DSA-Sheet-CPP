#include <bits/stdc++.h>
using namespace std;

// kruskals is disjoint set based data structure
class DisjointSet {
    vector<int> size, parent ;
public:
    DisjointSet (int n) {
        size.resize(n , 1) ; parent.resize(n) ;
        for(int i =0; i < n ; i++){parent[i] = i ;}
    }

// just a normal recursion
    int findPar (int node) {
        // base condition
        if(parent[node] == node) {
            return node ;
        }

        return parent[node] = findPar(parent[node]) ;
    }

    void union_by_size(int u , int v) {
        int pu = findPar(u) , pv = findPar(v) ;

        // if the ultimate parents are same --> they are already in a union
        if(pu == pv) {
            return ;
        }

        // now again there can be 3 cases: 
        /* 
        size[pu] < size[pv] --> connect pu to pv and increase the size of pv
        size[pv] < size[pu]
        size[pu] == size[pv] --> connect any one of them to other
        */

       if(size[pu] < size[pv]){
            parent[pu] = pv ;
            size[pv] += size[pu] ;
       }
       else{
            // means either size[pu] == size[pv] or size[pu] > size[pv] --> in both the cases we can connect pv to pu

            parent[pv] = pu ;
            size[pu] += size[pv] ;
       }
    }

    bool isSameComponent (int u, int v) {
        return (findPar(u) == findPar(v)) ;
    }
};

class Solution{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here

        // first we need to form a vector containing all the edges
        vector<pair<int, pair<int,int>>> edges ;
        for(int u = 0 ; u < V ; u++){

            // ith node
            for(auto x : adj[u]) {
                int v = x[0] , wt = x[1] ;
                edges.push_back({wt , {u , v}}) ;
            }
        }

        // since we have to form the min spanning tree , we need all the edges from small -> big (ascending order)
        sort(edges.begin() , edges.end()) ;

        // kruskals is a disjoint set based structure
        DisjointSet ds (V); // graph is 0-indexed based
        int mst = 0 ;

        // kruskal ki kahani  : since we have to use disjoint set to make a mst 
        /* 
        in a mst we have exactly (all the edges of the graph) N nodes and N-1 edges , without any cycle .
        cycle ki ek pehchaan --> agar ek hi node ko waapis visit kr lie means theres a cycle
        also the edges in mst are those having smallest weights between two nodes 

        conclusion:
        use disjoint set --> consider only those edges jinke ultimate parents same na ho (which means they are not connected yet)
        sorting provides us the edges in a increasing order so the edge with smaller weight will appear first
        if two nodes are not connected (means there parents are not same) -> perform union b/w them and add the edge weight in ans
        */

        for(auto it: edges) {
            int wt= it.first , u= it.second.first , v = it.second.second ;
            if(ds.findPar(u) != ds.findPar(v)) {
                mst += wt ;
                ds.union_by_size(u , v) ;
            }
        }

        return mst ;

    }
};