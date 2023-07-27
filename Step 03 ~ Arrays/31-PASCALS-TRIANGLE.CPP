#include <bits/stdc++.h>
#define ll long long
using namespace std;

// BEST-TRICK : https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    
    // function to calculate nCr = (factorial(n)) / (factorial(r) * factorial(n-r))

    long long ncr (int n, int r) {

        long long res = 1 ;
        for(int i =0 ; i < r; i++) {
            res = res * (n-i) ;
            res = res / (i+1) ;
        }

        return (int)(res) ;

    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans ;

        for(int i = 1 ; i <= numRows ;i++) {
            vector<int> temp ;
            for(int j = 1 ; j <= i ; j++) {
                temp.push_back (ncr(i-1, j-1)) ;
            }
            ans.push_back(temp) ;
        }
        return ans ;
        
    }
};