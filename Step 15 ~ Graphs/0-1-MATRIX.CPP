#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        // Code here
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>> distance (n , vector<int>(m , 1e9)) ; // distance matrix would store the distance of nearest 1 from any cell --> if for a cell its value is 1e9 means the cell is unvisited else its visited and then we would replace the value at cell with that min distance value

        int row_changes[] ={-1 , 0 , 1 , 0} , col_changes[] = {0 , 1 , 0, -1} ;

        queue<pair<pair<int,int> , int>> q ; // < <row, col> , distance >
        
        // there is atleast one 1 in the matrxi as given in the problem
        for(int i=0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j} , 0});
                    distance[i][j] = 0; // mark the cell with 1
                }
            }
        }

        while(!q.empty()){
            auto x = q.front() ; q.pop() ;
            int row = x.first.first , col = x.first.second , dis = x.second ;

            for(int k = 0 ; k < 4 ; k++){
                int i = row + row_changes[k] , j = col + col_changes[k] ;
                if(i >= 0 and i < n and j >= 0 and j < m and grid[i][j]==0){
                    // we would not consider any cells with value 1 bcz wo to phle se hi min distance pr stored hain unko lekar bother kyu krna
                    
                    // if the cell has value 0 and the prev distance is greater than current distance then modify the value of the grid and push it in the queue
                    if(distance[i][j] > dis + 1){
                        distance[i][j] = dis + 1 ;
                        q.push({{i , j} , distance[i][j]}) ;
                    }
                }
            }
        }

        return distance ;

    }
};