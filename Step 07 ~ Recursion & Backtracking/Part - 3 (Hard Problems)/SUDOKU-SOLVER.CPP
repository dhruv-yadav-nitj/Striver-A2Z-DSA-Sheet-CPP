#include <bits/stdc++.h>
using namespace std;

// leetcode version
class Solution {
public:
    bool isValid (vector<vector<char>> board, int row, int col, char c){

        for(int i =0 ; i <9 ; i++){

            // check for row
            if(board[row][i] == c){
                return false ;
            }

            // check for col
            if(board[i][col]== c){
                return false;
            }

            // check in the 3x3 box
            if(board[(row/3) * 3 + (i/3)][(col/3) * 3 + (i%3)]== c){
                return false;
            }
        }

        return true ;

    }

    bool recursion (vector<vector<char>>&board){
        for(int i =0 ;i < 9 ; i++){
            for(int j= 0; j < 9 ;j++){

                if(board[i][j]== '.'){

                    // the cell is empty
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isValid(board, i , j , c)){
                            board[i][j] = c ;

                            if(recursion(board)){
                                return true ;
                            }
                            else{
                                board[i][j] = '.' ;
                            }
                        }
                    }

                    return false ;
                }
            }
        }

        return true ;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool solve = recursion(board) ;        
    }
};



// gfg version
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool isValid (int board[N][N], int row, int col, int c){

        for(int i =0 ; i <9 ; i++){

            // check for row
            if(board[row][i] == c){
                return false ;
            }

            // check for col
            if(board[i][col]== c){
                return false;
            }

            // check in the 3x3 box
            if(board[(row/3) * 3 + (i/3)][(col/3) * 3 + (i%3)]== c){
                return false;
            }
        }

        return true ;

    }

    bool recursion (int grid[N][N]){
        for(int i =0 ;i < 9 ; i++){
            for(int j= 0; j < 9 ;j++){

                if(grid[i][j]== 0){

                    // the cell is empty
                    for(int c = 1 ; c <= 9 ; c++){
                        if(isValid(grid, i , j , c)){
                            grid[i][j] = c ;

                            if(recursion(grid)){
                                return true ;
                            }
                            else{
                                grid[i][j] = 0 ;
                            }
                        }
                    }

                    return false ;
                }
            }
        }

        return true ;
        
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        bool solve= recursion(grid) ;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i< N; i++){
            for(int  j =0 ;j < N ; j++){
                cout << grid[i][j] << " " ;
            }
        }
    }
};