#include <bits/stdc++.h>
using namespace std;


// vvv imp problem implementation wise
// logic is clear and very simple but implementing the problem is real tough

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
    int maxRemove(vector<vector<int>> &stones, int n){
        // Code here
        
        int maxiRow = INT_MIN , maxiCol = INT_MIN ;
        for(auto it : stones) {
            int r= it[0] , c= it[1] ;
            maxiRow= max(r, maxiRow) , maxiCol = max(maxiCol , c) ;
        }

        // suppose the maxRow = 2 and maxCol = 2 -> on converting it to 1-D array it would be like 0, 1, 2, | 3, 4, 5 -> which needs a disjoint set of size 6 so maxRow + maxCol + 2

        DisjointSet ds(maxiRow + maxiCol + 2) ;

        unordered_map<int,int> mp ;

        for(auto it : stones) {
            // since we cant reprsent 2-d matrix on a graph -> we woudl convert the cells of 2-d matrix into some single representation
            // start col index from end of row , it would make 2-d matrix a 1-d array type
            int u = it[0] , v = it[1] + maxiRow + 1 ;
            ds.union_by_size(u , v) ;

            // mark that there was some stone placed
            mp[u] = 1 ; mp[v] = 1 ;
        }

        int ans = n ; 
        for(int i =0; i < maxiRow + maxiCol + 2 ; i++) {

            if(mp.count(i)){
                // if at this index there was a stone then

                if(ds.findPar(i) == i){
                    ans-- ;
                }
            }
        }

        return ans ;
    }
};