#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
        // code here

        // approach : just apply djikstra's algorithm

        int n= grid.size() , m = grid[0].size() , sr = source.first, sc = source.second , dr = destination.first , dc =destination.second ;
        vector<vector<int>> distance (n , vector<int> (m , 1e9));

        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq ;
        pq.push({0, {sr, sc}}) ; distance[sr][sc]= 0 ; // <distance , <row, col>>

        // row and col changes to move in the 4-direction
        int row_changes[] = {-1, 0, 1, 0} , col_changes[] = {0 , 1 , 0, -1} ;

        while(!pq.empty()) {
            int row = pq.top().second.first , col = pq.top().second.second , dis = pq.top().first ; pq.pop() ;

            int newDist = dis + 1 ; // all the cells on its 4 sides would be 1 more away from the dis it is away from the source

            if(row == dr and col == dc){
                return dis ;
            }

            for(int k = 0 ; k < 4 ; k++){
                int i = row + row_changes[k] , j = col + col_changes[k];
                if(i >= 0 and i < n  and j >= 0 and j < m and grid[i][j] == 1 and newDist < distance[i][j]){
                    distance[i][j] = newDist ;
                    pq.push({newDist, {i , j}}) ;
                }
            }

        }

        return -1 ;

    }
};