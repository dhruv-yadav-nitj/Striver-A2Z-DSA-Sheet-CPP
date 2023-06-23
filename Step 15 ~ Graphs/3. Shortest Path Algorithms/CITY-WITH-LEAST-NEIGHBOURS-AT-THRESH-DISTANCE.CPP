#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold){
        // code here

        // create a adj matrix out of the given data
        vector<vector<int>> matrix (n , vector<int> (n , 1e9)) ;
        for(auto it : edges) {
            int u= it[0] , v =it[1] , wt= it[2] ;
            matrix[u][v]= wt ; matrix[v][u]= wt ;
        }

        for(int i=0; i < n ; i++){
            for(int j=0; j <n; j++){
                if(i == j){matrix[i][j]=0 ;}
            }
        }

        // simple apply the floyd warshall algorithm to calculate the min distance of each node from every other node
        for(int k =0 ; k < n ; k++){
            for(int i=0; i < n ; i++){
                for(int j =0; j < n ; j++){
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]) ;
                }
            }
        }

        int ans = 0 , count = INT_MAX ;
        for(int i =0; i < n ; i++){
            int temp(0);
            for(int j = 0; j < n ; j++){
                if(matrix[i][j] <= distanceThreshold){
                    temp++ ;
                }
            }

            if(temp <= count){
                ans = i , count= temp ;
            }
        }

        return ans ;
    }
};