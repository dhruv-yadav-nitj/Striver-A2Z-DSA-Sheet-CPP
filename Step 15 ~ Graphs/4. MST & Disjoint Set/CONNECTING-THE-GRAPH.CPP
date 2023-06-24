#include <bits/stdc++.h>
using namespace std ;

class DisjointSet {
    vector<int> size, parent ;
public:
    DisjointSet (int n) {
        size.resize(n  , 1) ; parent.resize(n) ;
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
    int Solve(int n, vector<vector<int>> &edge){
        // code here
        
        DisjointSet ds (n) ;
        int xtra = 0 ;

        for(auto it : edge) {
            int u = it[0] , v =it[1] ;
            if(ds.findPar(u) == ds.findPar(v)) {
                xtra++ ;
            }
            else{
                ds.union_by_size(u , v) ;
            }
        }

        int comp = -1 ; // because it would always count 1 extra component (the most parent component jisme hme baaki saare components add krne hain)
        for(int i =0 ; i < n ; i++){
            if(ds.findPar(i) == i) {
                comp++;
            }
        }

        if(comp  > xtra){
            return -1 ;
        }
        else{
            return comp ;
        }
    }
};