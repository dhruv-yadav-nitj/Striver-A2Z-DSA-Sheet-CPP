#include <bits/stdc++.h>
using namespace std;

// did this problem in Greedy Algorithms too -> Insert Intervals, Merge Intervals, etc.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
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