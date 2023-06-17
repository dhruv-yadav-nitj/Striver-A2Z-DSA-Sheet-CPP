#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:

    // function to check whether a color 'col' fits valid in the node nth
    bool isValid (bool graph[101][101] , int n , int node, int col, int color[]){
        
        // check if any of the adjacent nodes of node 'node' have the same color as col
        for(int i = 0 ;i < n ; i++){
            if(graph[node][i] == 1 and color[i] == col){
                return false ;
            }
        }

        return true ;
    }

    bool recursion (bool graph[101][101], int n , int m , int color[] , int node){
        // base condition
        // if we reached the last node
        if(node == n){
            return true ;
        }

        // we have to try to color the current node using color from 1  to m
        for(int i=1 ; i<= m ; i++){
            if(isValid(graph , n , node, i, color)){
                color[node] = i ;
                
                if(recursion(graph , n , m, color , node+1)){
                    return true ;
                }

                // if the ith color fits perfect in the node then call for further nodes else if it does not then we dont have to return false (warna khela khtm) else we have to try for remaining colors
                color[node] =0 ;
            }
        }

        // if no color fits perfect in the node then return false
        return false ;

    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0} ;
        return recursion(graph, n , m , color, 0) ;
    }
};