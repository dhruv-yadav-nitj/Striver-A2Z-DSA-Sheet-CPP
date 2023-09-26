#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here

        vector<vector<int>> dp (N , vector<int> (M , 0)) ;
        int ans = 0 ;

        for(int i =0 ; i < N ; i++) {
            for(int j = 0 ; j < M ; j++) {
                if(i ==0 or j ==0) {
                    dp[i][j] = matrix[i][j] ;
                }
                else{
                    if(matrix[i][j] ==0 ){
                        dp[i][j] =0 ;
                    }
                    else{
                        // according to the given intuition explained in tutorial
                        dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) ;
                    }
                }
                ans = ans + dp[i][j] ;
            }
        }

        return ans ;

    }
};