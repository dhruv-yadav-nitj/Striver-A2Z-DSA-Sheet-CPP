#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

class Solution {
public:
    void rotateby90(vector<vector<int>> &matrix, int n) {
        // code here

        // transpose the matrix
        for(int i =0 ; i < n ; i++) {
            for(int j =i ; j < n ; j++) {
                swap(matrix[i][j] , matrix[j][i]) ;
            }
        }

        // reverse the columns
        for(int j =0; j< n; j++) {
            for(int i =0 ; i < n/2 ; i++) {
                swap(matrix[i][j] , matrix[n-1-i][j]) ;
            }
        }
    }
};