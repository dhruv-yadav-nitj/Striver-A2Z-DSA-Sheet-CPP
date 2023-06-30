#include <bits/stdc++.h>
using namespace std;

// if u understood prev problem (INSERT INTERVAL) clearly -> this problem would be halwa
// problem link: https://bit.ly/3K6pRlt

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals) {
        // Code here
        sort(intervals.begin() , intervals.end()) ; // sort the intervals on the basis of their start
        vector<vector<int>> ans ; vector<int> curr = intervals[0] ;

        int n = intervals.size() ;
        for(int i =1; i < n ;i++) {
            // case 1 : 
            if(curr[1] < intervals[i][0]) {
                ans.push_back(curr) ;
                curr = intervals[i] ; continue;
            }
            else{
                curr[0] = min(curr[0] , intervals[i][0]) ;
                curr[1] = max(curr[1] , intervals[i][1]) ;
            }
        }
        ans.push_back(curr) ;
        return ans ;

    }
};