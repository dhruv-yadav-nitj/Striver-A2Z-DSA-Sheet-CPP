#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs (vector<vector<int>>&grid ,int n, int m, int row , int col, vector<vector<int>>&isVisited, vector<pair<int, int>>&vec, int baseRow , int baseCol){

        isVisited[row][col] = 1 ;

        vec.push_back({
            row - baseRow, col - baseCol
        });

        int row_changes[] = {-1 , 0 , 1 , 0} , col_changes[]= {0 , 1, 0 , -1} ;
        vector<string> direction = {"U" , "R" , "D" , "L"} ;
        for(int k = 0 ; k < 4 ; k++){
            int i = row + row_changes[k] , j= col+ col_changes[k] ;
            string turn  = direction[k] ;
            if(i >= 0 and i < n and j >= 0 and j < m and grid[i][j]==1 and !isVisited[i][j]){
                dfs(grid , n, m , i , j , isVisited , vec,  baseRow , baseCol) ;
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid){
        // code here

        // we would be applying modified dfs traversal and to count unique number of islands we would be using a set to store the traversal directions --> always go in this sequence (D --> L --> R --> U)

        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>> isVisited (n, vector<int> (m, 0)) ;

        set<vector<pair<int, int>>> st ;
        for(int i=0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 and !isVisited[i][j]){
                    vector<pair<int, int>> vec ;
                    dfs(grid, n , m , i , j , isVisited, vec, i, j) ;
                    st.insert(vec) ;
                }
            }
        }

        return st.size() ;

    }
};