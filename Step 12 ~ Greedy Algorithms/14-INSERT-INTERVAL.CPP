#include <bits/stdc++.h>
using namespace std;

// best explanation to this problem -> https://youtu.be/A8NUOmlwOlM

class Solution {
public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        vector<vector<int>> ans ;

        for(int i = 0 ; i < N ; i++) {
            // case 1 : if the e < s[i]
            if(newEvent[1] < intervals[i][0]) {
                ans.push_back(newEvent) ;
                for(int j =i ; j < N ;j++) {
                    ans.push_back(intervals[j]) ;
                }
                return ans;
            }
            // case 2 : if s > e[i]
            else if(newEvent[0] > intervals[i][1]) {
                ans.push_back(intervals[i]) ;
            }
            // else we need now to merge
            else{
                newEvent = {min(newEvent[0] , intervals[i][0]) , max(newEvent[1], intervals[i][1])} ;
            }
        }

        ans.push_back(newEvent) ; return ans ;

    }
};