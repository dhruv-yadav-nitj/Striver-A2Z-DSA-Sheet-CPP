#include <bits/stdc++.h>
using namespace std ;

// disjoint set using union by rank
class DisjointSet {
    vector<int> rank , parent ;
public:
    DisjointSet (int n){
        // assuming 1-index based graph
        rank.resize(n+1 , 0) , parent.resize(n+1) ;
        for(int i =0; i < n+1 ; i++){parent[i] = i ;}
    }

// just a normal recursion
    int findPar (int node) {

        // base condition
        if(parent[node] == node) {
            // means its the ultimate parent
            return node ;
        }
        // path compression
        return parent[node] = findPar(parent[node]) ;
    }

    void union_by_rank (int u , int v) {
        int pu = findPar(u) , pv = findPar(v) ;

        // if the ultimate parents are same then they are already in a union
        if(pu == pv){
            return ;
        }

        // if rank(pu) < rank(pv) then connect pu to pv and no change in rank
        // if rank[pu]==rank[pv] then we can connect any one of them to other so we connected pu to pv and in this case there would increment of 1 in rank of pv (do a dry run and understand)
        if(rank[pu] <= rank[pv]) {
            parent[pu] = pv ;
            if(rank[pu] == rank[pv]){
                rank[pv]++ ;
            }
        }
        else{
            parent[pv]= pu ;
        }
    }

    bool isSameComponent (int u , int v) {
        return (findPar(u) == findPar(v)) ;
    }
};

// disjoint set using union by size

// not much different from union by rank --> size of each node would be 1 initially (whereas rank was 0) and when performing union --> if size(u) > size(v) --> then connect v to u and this case size(u) would increase by size(v) (whereas when performing union by rank there is no increase in rank in every case, which is obvious)

class DisjointSet {
    vector<int> size, parent ;
public:
    DisjointSet (int n) {
        size.resize(n +1 , 1) ; parent.resize(n +1) ;
        for(int i =0; i < n+1 ; i++){parent[i] = i ;}
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