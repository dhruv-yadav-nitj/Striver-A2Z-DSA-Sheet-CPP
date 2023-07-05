#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here

        vector<vector<int>> dp (N , vector<int> (M, 0)) ;
        // fill the first row
        for(int j =0 ; j < M ; j++) {dp[0][j]=  matrix[0][j] ;}
        // fill the first col
        for(int i =0 ; i < N ; i++) {dp[i][0]=  matrix[i][0] ;}

        // fill the rest of the dp using the formula
        for(int i =1 ; i < N ; i++) {
            for(int j = 1 ; j < M ; j++) {
                if(matrix[i][j] == 0) {dp[i][j] = 0 ;}
                dp[i][j] = min(min(dp[i-1][j-1] , dp[i-1][j]), dp[i][j-1]) + 1; // according to the intuition explained in tutorial
            }
        }
        
        int ans(0) ;
        // just add all the elements
        for(int i=0; i < N ; i++) {
            for(int j =0 ; j < M ; j++) {
                ans += dp[i][j] ;
            }
        }

        return ans ;
        

    }
};