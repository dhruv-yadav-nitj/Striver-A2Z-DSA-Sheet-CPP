#include <bits/stdc++.h>
using namespace std;

// very simple logic -> just use normal djikstra's algo

class Solution{
public:
    int Solve(int n, vector<vector<int>> &grid){
        // code here
        int m = n ;
        priority_queue < pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> > pq ;
        vector<vector<int>> time (n , vector<int> (m , 1e9)) ; // distance matrix for djikstra's algo

        time[0][0]= 0 ; pq.push({0 ,{0,0}}) ;

        int row_changes[] = {-1 , 0 , 1, 0} , col_changes[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto it = pq.top(); pq.pop() ;
            int t = it.first , i = it.second.first , j = it.second.second ;

            if(i == n-1 and j == m-1) {
                return t ;
            }

            for(int k = 0 ; k < 4 ; k++){
                int row = i+ row_changes[k] , col = j + col_changes[k] ;
                if(row >= 0 and row < n and col >= 0 and col < m){
                    int req = max(grid[i][j] , grid[row][col]) ;
                    if(t >= req){
                        if(t < time[row][col]){
                            pq.push({t , {row, col}}) ;
                            time[row][col]= t ;
                        }
                    }
                    else{
                        pq.push({req , {row, col}});
                        time[row][col] = req ;
                    }
                }
            }

        }

        return time[n-1][m-1] ;

    }
};