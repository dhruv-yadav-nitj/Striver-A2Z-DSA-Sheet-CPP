// FIRST DO PROBLEM "NUMBER-OF-ISLANDS"

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

/* 
Step 1: Connect all the existing components using the same approach as followed in the prev problem (Number of Islands)
Step 2: Now traverse the matrix again and if a cell contain 0 then this means we can modify it as 1 and can connect all the adjacent islands around it
Step 3: So we will do it (kind of brute force approach) -> but there's exist an edge case -> we can end up taking same island more than one times -> so this would be handled by storing the parents in a set data structure -> the edge case is very illustrated using image in the striver's article 
Step 4: The size of an island can be knows by taking the size of its ultimate parent node (union by size concept)

Article:
https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/
*/

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

    int sizeReturn (int u) {
        return size[findPar(u)] ;
    }
};

class Solution{
public:
    int MaxConnection(vector<vector<int>> &grid){
        // code here

        int n = grid.size() , m = grid[0].size() ;

        DisjointSet ds (n*m) ;
        int row_changes[] = {-1 , 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;

        vector<vector<int>> isVisited (n , vector<int> (m , 0)) ;

        for(int i =0 ; i < n ; i++) {
            for(int j=0 ; j < m ; j++){
                
                if(grid[i][j] == 1 and !isVisited[i][j]) {
                    int u = (i * m) + j ; isVisited[i][j] = 1 ;
                    for(int k = 0 ; k < 4 ; k++){
                        int row = i + row_changes[k] , col = j + col_changes[k] ;
                        if(row >= 0 and row < n and col >= 0 and col < n and grid[row][col]== 1) {
                            int v = (row * m) + col ;
                            ds.union_by_size(u , v) ;
                        }
                    }
                }
            }
        }

        int ans = 0 ;

        for(int i =0 ;i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 0) {
                    unordered_set <int> st ;

                    for(int k = 0 ; k < 4 ; k++) {
                        int row = i + row_changes[k] , col = j + col_changes[k] ;
                        if(row >= 0 and row < n and col >= 0 and col < n and grid[row][col] == 1) {
                            int cell = row * m + col ;
                            st.insert(ds.findPar(cell)) ;
                        }
                    }
                    int temp = 0 ;
                    for(auto it: st) {
                        temp += ds.sizeReturn(it) ;
                    }

                    ans = max (ans , temp + 1) ;
                }
            }
        }
        
        //  edge case: but what if the matrix has none of the 0s -> then the above ans would be 0 till now -> so in this case we would just take the largest island as our answer
        for(int i=0 ; i < n*m ; i++){
            ans= max(ans , ds.sizeReturn(ds.findPar(i))) ;
        }

        return ans ;
    }
};