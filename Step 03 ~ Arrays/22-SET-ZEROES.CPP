#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/description/

// Time ~ O(2*(n*m)) ; Space ~ O(2*n*m)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set <int> str , stc ;
        int n = matrix.size() , m = matrix[0].size() ;
        for(int i =0 ; i < n ; i++) {
            for(int j =0; j < m ; j++) {
                if(matrix[i][j] == 0){
                    str.insert(i) ; stc.insert(j) ;
                }
            }
        }
        for(int i =0 ; i < n ; i++) {
            for(int j =0 ; j < m ; j++) {
                if(str.count(i) or stc.count(j)) {
                    matrix[i][j] = 0 ;
                }
            }
        }
    }
};