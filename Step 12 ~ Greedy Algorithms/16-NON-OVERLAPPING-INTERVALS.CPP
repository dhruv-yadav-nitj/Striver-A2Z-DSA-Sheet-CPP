#include <bits/stdc++.h>
using namespace std;

// EASY Problem -> if you understood Problem #14 properly

class Solution {
public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin() , intervals.end()) ;
        int count (0) , end =intervals[0][1] ; // end of first interval

        for(int i =1 ; i < N ; i++) {
            // case 1 : if the current two intervals does not overlap -> end of prev interval is less than start of the current interval
            if(end <= intervals[i][0]) {
                end = intervals[i][1] ;
            }
            else{
                count++ ;
                // if both of them overlap -> we would choose the interval with smaller ending point -> because it would minimise the number of intervals we need to remove
                // suppose if we would have chosen the interval with large ending point we could have end up having that interval overlapping with its next interval
                // so better choose the interval with smaller ending point
                end = min(end , intervals[i][1]) ;
            }
        }

        return count ;

    }
};