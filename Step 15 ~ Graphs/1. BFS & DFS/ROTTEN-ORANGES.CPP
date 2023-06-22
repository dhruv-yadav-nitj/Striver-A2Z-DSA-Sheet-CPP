#include <bits/stdc++.h>
using namespace std;

// clearly we should use bfs
class Solution{
public:
    int orangesRotting(vector<vector<int>> &grid){
        // Code here

        queue<pair<pair<int, int> , int>> q ; // {{row, col} , time of rotting}
        int n = grid.size() , m = grid[0].size() ;

        // step 1 : push all the rotten oranges with the time 0
        for(int i = 0 ;i < n ; i++){
            for(int j= 0 ; j < m ; j++){
                if(grid[i][j]== 2){
                    q.push({{i, j} , 0}) ;
                }
            }
        }

        int time = 0 ;

        while(!q.empty()){
            auto it = q.front() ; q.pop() ;
            int row = it.first.first , col = it.first.second ;
            time = it.second ;

            int row_changes[] = {-1 , 0 , 1 , 0} , col_changes[] = {0 , 1 , 0 , -1} ;

            for(int k = 0 ; k < 4 ; k++){
                int i = row + row_changes[k] , j = col + col_changes[k] ;
                if(i >= 0 and j >= 0 and i < n and j < m and grid[i][j] == 1){
                    q.push({{i, j} , time+1}) ;
                    grid[i][j] = 2 ; // rot the oranges (similar to marking visited)
                }
            }
        }

        for(int i =0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    return -1 ;
                }
            }
        }

        return time ;

    }
};