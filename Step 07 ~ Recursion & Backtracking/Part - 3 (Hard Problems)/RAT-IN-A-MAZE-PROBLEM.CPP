#include <bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    void recursion (vector<vector<int>> maze , int n, vector<vector<int>> &isVisited , int row, int col , vector<string> &ans, string temp){

        // base case
        if(row == n-1 and col == n-1){
            ans.push_back(temp) ;
            return ;
        }

        // D --> L --> R --> U (order according to the ques)

        // down
        if(row +1 < n and !isVisited[row+1][col] and maze[row+1][col]==1){
            isVisited[row][col]= 1 ;
            recursion(maze, n, isVisited , row +1 , col , ans, temp + "D") ;

            // backtrack
            isVisited[row][col] = 0 ;
        }

        // left
        if (col - 1 >= 0 && !isVisited[row][col - 1] && maze[row][col - 1] == 1) {
            isVisited[row][col] = 1;
            recursion(maze, n, isVisited , row , col - 1 , ans, temp + "L") ;
            isVisited[row][col] = 0;
        }

        // right 
        if (col + 1 < n && !isVisited[row][col + 1] && maze[row][col + 1] == 1) {
            isVisited[row][col] = 1;
            recursion(maze, n, isVisited , row , col+1 , ans, temp + "R") ;
            isVisited[row][col] = 0;
        }

        // upward
        if (row - 1 >= 0 && !isVisited[row - 1][col] && maze[row - 1][col] == 1) {
            isVisited[row][col] = 1;
            recursion(maze, n, isVisited , row -1 , col , ans, temp + "U") ;
            isVisited[row][col] = 0;
        }

    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here

        vector<string> ans ;
        
        // isVisited matrix to keep track of visited cells
        vector<vector<int>> isVisited (n , vector<int> (n , 0)) ; // initially keep all of them as 0 which represents unvisited

        if(m[0][0] == 1){
            // call recursion if the first cell is 1
            recursion(m, n , isVisited, 0 , 0 , ans, "") ;
        }
        return ans ;

    }
};