#include <bits/stdc++.h>
using namespace std;

// using bfs
class Solution{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
        // Code here

        // we can either use bfs or dfs --> but I would be using bfs for my ease
        // Space ~ O(n*m) for the cloned image with new colors

        queue<pair<int, int>> q ;
        vector<vector<int>> clone = image ; // we are not making direct changes rather we are using a separate matrix
        
        vector<vector<int>> isVisited (image.size() , vector<int> (image[0].size() , 0)) ;

        // for moving around the 4 directions
        int row_changes[] = {-1 , 0 , 1, 0}, col_changes[] = {0 , 1, 0, -1} ;

        q.push({sr , sc}) ; clone[sr][sc] = newColor ;
        isVisited[sr][sc]= 1 ;
        while(!q.empty()){
            int row = q.front().first , col = q.front().second ; q.pop() ;

            for(int k = 0 ; k < 4 ; k++){

                int i = row+row_changes[k] , j = col+col_changes[k] ;
                // consider only those neighbouring nodes whose cloned color are equal to the old color of current nodes (since acc to problem we can chane only those nodes) and are also unvisited (if we would not consider isVisited then we would end up taking the same nodes again and again in the queue and it will end up with TLE, do a dry run on the given testcase to understand this edge case)
                if(i >= 0 and j >= 0 and i < image.size() and j < image[0].size() and clone[i][j] == image[row][col] and !isVisited[i][j]){
                    q.push({i , j}) ; clone[i][j] = newColor ;
                    isVisited[i][j] = 1 ;
                }
            }
        }

        return clone ;

    }
};