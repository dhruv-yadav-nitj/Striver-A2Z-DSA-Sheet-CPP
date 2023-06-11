#include <bits/stdc++.h>
using namespace std ;

// https://leetcode.com/problems/find-a-peak-element-ii/
// https://www.geeksforgeeks.org/find-peak-element-2d-array/

// important ques for interviews

// Time ~ O(logn * m)

/* Approach
Consider low= 0 and high = n -1 (index of last row)
find mid row --> and then find the max element in this row using a for loop iterating over 0 to m (total no of cols)
// since in finding peak element we always track the max element (as learned in finding peak element in 1d array)

compare it along its 2 sides (up and down)
why only up and down --> since we have already selected the max element out of that row so no need to compare the same element again

// if its the peak element then return else track the max element found
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // your code here

        int n = mat.size() , m = mat[0].size() ;
        int low =0 , high = n-1, mid ;

        while(low <= high){

            mid = low + (high -low)/2 ;
            int maxi= INT_MIN, col=0;
            for(int j = 0 ; j < m ; j++){
                if(maxi < mat[mid][j]){
                    maxi = mat[mid][j] ; col = j ;
                }
            }

            // now compare the maxi element with just upper and lower elements in the same col
            if(mid ==0) {
                if(mat[mid][col] > mat[mid+1][col]){
                    return {mid, col} ;
                }
                else{
                    low =mid+1 ;
                }
            }

            else if(mid == n-1){
                if(mat[mid][col] > mat[mid -1][col]){
                    return {mid, col} ;
                }
                else{
                    high = mid-1 ;
                }
            }

            else if(mat[mid][col] > mat[mid-1][col] and mat[mid][col] > mat[mid+1][col]){
                return {mid , col} ;
            }

            else if(mat[mid][col] < mat[mid-1][col]){
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }

        return {-1, -1} ;

    }
};