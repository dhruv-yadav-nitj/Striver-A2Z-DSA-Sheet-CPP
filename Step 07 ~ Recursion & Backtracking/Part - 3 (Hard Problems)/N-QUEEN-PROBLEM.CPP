#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    bool isValid (vector<vector<int>>board, int row , int col){
        
        int i = row , j = col ;
        // check the left side for current row
        while(j >= 0){
            if(board[i][j]==1){
                return false ;
            }
            j-- ;
        }

        i = row , j = col ;
        // check the upper diagonal on the left side
        while(i >= 0 and j >= 0){
            if(board[i][j] == 1){
                return false ;
            }
            i-- , j-- ;
        }

        i = row , j =col ;
        // check the downward diagonal on the left side
        while(i < board.size() and j >= 0){
            if(board[i][j]==1){
                return false ;
            }
            i++ , j-- ;
        }

        // since everything's fine then return true
        return true ;
    }
    void recursion (vector<vector<int>>&board, int curr_col , vector<int>temp , vector<vector<int>>&ans, int n){

        // base case
        if(curr_col == n){
            ans.push_back(temp) ;
            return ;
        }

        for(int i= 0 ; i < board.size() ; i++){
            // col to whi curr_col hi rhega but row change hota rhega
            if(isValid(board, i, curr_col)){

                // if the current setup is valid then place the queen in this cell and then recur for the next column
                board[i][curr_col] = 1 ;
                temp.push_back(i +1 ) ;

                recursion(board, curr_col +1 , temp , ans , n) ;

                // chahe aage jaakr ye setup success ho ya na ho hme backtrack to krna hi pdhega to check for any other possible answers
                // backtrack
                board[i][curr_col] = 0 ;
                temp.pop_back() ;
            }
        }

    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans ;
        vector<vector<int>> board (n , vector<int>(n , 0)) ; // configure the board and initialise all the cells as 0 (which represents that queen is not present there)

        recursion(board, 0, {} , ans , n) ;

        return ans ;
    }
};