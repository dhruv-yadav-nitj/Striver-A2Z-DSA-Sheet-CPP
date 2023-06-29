#include <bits/stdc++.h>
using namespace std;

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Intuition
// Say if you have two meetings, one which gets over early and another which gets over late. Which one should we choose? -> obviously the former one

class Solution {
public:
    bool comparator (const pair<int,int> &a, const pair<int,int>&b) {
        return a.second < b.second ;
    }
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector<pair<int,int>> meetings ;
        for(int i =0 ; i < n ; i++) {
            meetings.push_back({start[i] , end[i]}) ;
        }

        // sort the meetings in order of their ending time (the meeting which ends first would come first)
        sort(meetings.begin() , meetings.end() , comparator) ;

        int count = 0 , last = INT_MIN ; // count -> meetings accomodated , last -> would store the finish time of last attended meeting
        for(auto x : meetings) {
            int s = x.first , e = x.second ;
            // we can choose a meeting only if the start time of this meeting is greater than the ending time of last ended meeting
            if(s > last) {
                count++ ; last= e ;
            }
        }

        return count ;

    }
};