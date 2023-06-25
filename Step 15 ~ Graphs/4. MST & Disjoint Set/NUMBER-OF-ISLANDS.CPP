#include <bits/stdc++.h>
using namespace std;

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

// Approach :
/* 
use formula to convert row, cell representation to a single entity and treat this as a node
total no. of nodes : (n * m)
mark all the cell which have '1' into a hashmap
traverse across the matrix and if a cell contains '1' then mark it in hashmap and traverse across its all 8 directions and if any cell contains '1' then perform union of both the nodes
traverse across the map and count++ when a node is the parent of itself
this approach kindof similar to performing bfs or dfs
*/

class Solution{
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid){
        // Code here

        int n = grid.size() , m = grid[0].size() ;

        // now we can convert a cell into a graph's node if we do this -> (i * n) + (j) -> where i : curr row , j : curr col , n : total cols

        // total cells : (n * m)
        DisjointSet ds (n*m) ; unordered_map<int, int> mp ;

        int row_changes[] = {-1 , -1 , 0 , 1 , 1 , 1, 0, -1} , col_changes[] = {0, 1, 1, 1, 0, -1, -1, -1} ;

        for(int row =0;row  < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == '1') {
                    int u= (row * m) + (col);
                    mp[u] = 1 ;

                    for(int k = 0 ; k < 8 ; k++){
                        int i = row + row_changes[k] , j = col+ col_changes[k] ;
                        if(i >= 0 and i < n and j >= 0 and j< m and grid[i][j] == '1'){
                            int v = (i * m) + (j) ;
                            ds.union_by_size(u , v) ;
                        }
                    }
                }
            }
        }
        int count=0 ;
        for(auto it : mp) {
            if(it.second == 1) {
                if(ds.findPar(it.first) == it.first){
                    count++ ;
                }
            }
        }

        return count ;
    }
};