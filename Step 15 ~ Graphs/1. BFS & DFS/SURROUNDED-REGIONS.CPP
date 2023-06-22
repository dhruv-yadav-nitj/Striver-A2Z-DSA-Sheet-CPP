#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    void dfs (vector<vector<char>>&mat , int n , int m , vector<vector<int>>&isVisited , int row, int col){
        isVisited[row][col] =1  ;
        
        int row_changes[] = {-1 , 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;

        for(int k= 0;k< 4 ; k++){
            int i = row + row_changes[k] , j = col + col_changes[k] ;
            if(i >= 0 and i < n and j >= 0 and j < m and mat[i][j]== 'O' and !isVisited[i][j]){
                dfs(mat, n , m , isVisited, i , j) ;
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here

        // its very hard to check which 0s can we replace so why not check which 0s we cant replace

        // basically we cant replace any 0s that are placed at any boundary row or column and all the other 0s that are connected to these 0s --> so we woudl apply dfs to mark this 0s and will then replace all the other 0s with Xs

        vector<vector<int>> isVisited (n, vector<int> (m ,0));
        
        // traverse first and last row
        for(int col = 0 ;col < m ; col++){

            if(mat[0][col] == 'O' and !isVisited[0][col]){
                dfs(mat , n , m, isVisited , 0 , col) ;
            }

            if(mat[n-1][col] == 'O' and !isVisited[n-1][col]){
                dfs(mat , n , m , isVisited , n-1 , col) ;
            }

        }

        // traverse first and last col
        for(int row = 0 ;row < n; row++){

            if(mat[row][0] == 'O' and !isVisited[row][0]){
                dfs(mat , n , m, isVisited , row, 0) ;
            }

            if(mat[row][m-1] == 'O' and !isVisited[row][m-1]){
                dfs(mat , n , m, isVisited , row, m-1) ;
            }
        }

        // after marking all the non replacable 0s replace all the 0s
        for(int i=0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!isVisited[i][j]){
                    mat[i][j] = 'X' ;
                }
            }
        }
        return mat ;

    }
};