#include <bits/stdc++.h>
using namespace std;

// djikstra and bellman ford were single source shortest path algorithms but floyd warshall is multi-source shortest path algorithm

// in this problem we would find shortest path from all the nodes to all the other nodes

class Solution{
public:
    void shortest_distance(vector<vector<int>> &matrix){
        // Code here
        int n = matrix.size() ; // there are n nodes (0 , 1, 2, .. n-1)

        // since the nodes which are not connected are represented by -1 in the matrix --> replace -1 with 1e9
        for(int i =0 ;i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j]== -1) {
                    matrix[i][j]= 1e9 ;
                }
                
                if(i == j) {
                    matrix[i][j]=0;
                }
            }
        }

        for(int k = 0 ; k < n; k++) {
            // from i to j via k
            for(int i =0; i < n ; i++){
                for(int j = 0; j < n ; j++) {
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]) ;
                }
            }
        }

        // iterate again if the distance b/w two nodes can be minimised further then we can say that negative cycle is present

        for(int i =0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 1e9) {
                    matrix[i][j] = -1 ;
                }
            }
        }
    }
};