#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int MinimumEffort(vector<vector<int>> &heights){
        // Code here

        int n = heights.size() , m = heights[0].size() ;
        int sr= 0 , sc= 0 , dr = heights.size() - 1 , dc = heights[0].size() - 1 ;
        
        // requirements
        vector<vector<int>> distance (n , vector<int> (m , 1e9)) ;
        priority_queue< pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>> > pq ;

        pq.push({0 , {sr, sc}}) ;
        distance[0][0] = 0 ;


        // row and col changes
        int row_changes[] = {-1 , 0 , 1 ,0} , col_changes[] = {0, 1, 0, -1} ;

        while(!pq.empty()) {
            int effort = pq.top().first , row = pq.top().second.first ,col = pq.top().second.second ;
            pq.pop() ;

            if(row == dr and col == dc) {return effort ;}

            for(int k = 0 ; k< 4 ; k++){
                int i = row + row_changes[k] , j = col + col_changes[k] ;
                if(i >=0 and i < n and j >= 0 and j < m){

                    int newEffort = max (effort , abs(heights[row][col] - heights[i][j])) ;
                    if(newEffort < distance[i][j]) {
                        distance[i][j] = newEffort ;
                        pq.push({newEffort , {i , j}}) ;
                    }
                }
            }
        }

        return -1 ;
    }
};