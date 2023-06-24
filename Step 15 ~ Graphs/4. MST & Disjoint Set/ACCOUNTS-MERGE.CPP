#include <bits/stdc++.h>
using namespace std;

// a good problem implementation wise -> though the logic is quite simple

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
    vector<vector<string>> mergeDetails(vector<vector<string>> &details){
        // code here
        int n = details.size() ;

        DisjointSet ds (n) ;

        unordered_map<string, int> mp ;
        for(int i =0; i < n ; i++){
            for(int j = 1 ; j < details[i].size() ; j++){

                string mail = details[i][j] ;
                if(mp.count(mail)) {

                    // if the mail exist already in the map --> then do union
                    ds.union_by_size(i , mp[mail]) ;
                }
                else{
                    mp[mail] = i ;
                }
            }
        }

        vector<string> accounts[n] ; // accounts would be identified on tha basis of their index
        for(auto it : mp){
            string mail = it.first ; int index =it.second;
            accounts[ds.findPar(index)].push_back(mail) ;
        }

        vector<vector<string>> ans ;
        for(int i =0 ;i < n ; i++) {
            if(accounts[i].size() != 0) {
                // if the account is not empty
                sort(accounts[i].begin() , accounts[i].end()) ;
                vector<string> curr ; curr.push_back(details[i][0]) ; // push the name first
                for(auto it: accounts[i]) {
                    curr.push_back(it) ;
                }
                ans.push_back(curr) ;
            }
        }

        sort(ans.begin() , ans.end()) ; return ans ;
    }
};

// there was some kind of problem in submitting the code on gfg
// though the code just worked fine on leetcode