#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool recursion (vector<vector<char>> board, string word, int index, vector<vector<int>>&isVisited, int row, int col){
        
        // base case : we would return true when we found the word
        if(index == word.length()){
            return true ;
        }

        // base case : we would return false when we can't find the word
        if(row < 0 or col < 0 or row >= board.size() or col >= board[0].size() or board[row][col] != word[index] or isVisited[row][col]){
            return false ;
        }

        // mark the current cell as visited
        isVisited[row][col] = 1 ;

        // check up down right left
        bool top = recursion(board, word, index +1 , isVisited , row -1 , col) ;

        bool right = recursion(board, word, index +1 , isVisited , row , col+1) ;
        
        bool down = recursion(board, word, index +1 , isVisited , row+1 , col) ;
        
        bool left = recursion(board, word, index +1 , isVisited , row , col-1) ; 

        // backtrack by marking the current cell as not visited
        isVisited[row][col] = 0 ;

        return (top or right or down or left) ;

    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here

        // first we have to start from the very first letter of the word
        for(int i =0; i < board.size() ; i++){
            for(int j= 0 ; j < board[i].size() ; j++){
                if(board[i][j] == word[0]){
                    // return what the recursion call returns you
                    vector<vector<int>> isVisited (board.size() , vector<int> (board[0].size() , 0)) ;
                    if(recursion(board, word, 0 , isVisited , i , j)){
                        return true ;
                    }
                }
            }
        }

        // means even the first letter was not found in the board --> return false
        return false ;

    }
};