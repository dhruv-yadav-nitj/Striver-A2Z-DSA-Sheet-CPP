#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs (vector<vector<int>>&grid , int n, int m , vector<vector<int>>&isVisited, int row, int col){
        isVisited[row][col] = 1 ;

        int row_changes[] = {-1 , 0 , 1 , 0} , col_changes[] = {0 , 1 , 0, -1} ;

        for(int k = 0 ; k < 4 ; k++){
            int i = row + row_changes[k] , j = col + col_changes[k] ;
            if(i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == 1 and !isVisited[i][j]){
                dfs(grid , n , m , isVisited, i , j) ;
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid){
        // Code here

        // similar to the exact previous problem in the A2Z Sheet (SAME CONCEPT USED)
        // see the problem SURROUNDED-REGIONS for the concept
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>> isVisited (n , vector<int> (m ,0)) ;

        // mark the 1s in 1st and last column
        for(int row = 0 ; row < n ; row++){
            if(grid[row][0] == 1 and !isVisited[row][0]) {
                dfs(grid, n , m , isVisited, row , 0) ;
            }


            if(grid[row][m-1] == 1 and !isVisited[row][m-1]){
                dfs(grid, n, m, isVisited , row, m-1) ;
            }
        }


        // mark the 1s in 1st and last row
        for(int col = 0; col < m ; col++){
            if(grid[0][col] == 1 and !isVisited[0][col]){
                dfs(grid , n , m , isVisited , 0 , col) ;
            }

            if(grid[n-1][col] == 1 and !isVisited[n-1][col]){
                dfs(grid , n , m , isVisited , n-1, col) ;
            }
        }

        int count = 0 ;
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 and !isVisited[i][j]){
                    count++ ;
                }
            }
        }

        return count ;
    }
};