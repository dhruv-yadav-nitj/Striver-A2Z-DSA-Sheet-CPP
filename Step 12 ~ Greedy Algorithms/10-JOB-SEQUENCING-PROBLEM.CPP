#include <bits/stdc++.h>
using namespace std;

// Nice Problem -> loved the intuition

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution {
public:
    static bool comparator (const pair<int,int>&a , const pair<int,int>&b) {
        return a.first > b.first ;
    }
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here

        // since we have to maximise our profit -> we should choose tasks with max profit first
        vector<pair<int,int>> jobs ;
        for(int i =0 ; i < n ; i++) {
            jobs.push_back({arr[i].profit , arr[i].dead}) ;
        }

        sort(jobs.begin() , jobs.end(), comparator) ;

        // 1 <= Deadline <= N
        int count (0) , profit (0) ; vector<int> booked (n + 1, 0) ;
        // count -> no. of jobs we can do , profit -> total profit from those jobs done , booked -> tells us whether a particular day is free or have i assigned some job to that day

        // intuition -> since the arr is sorted in decreasing order of profit -> job with max profit comes first
        // it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs (suppose two jobs with very much profit have same deadline -> so we would want to perform both jobs -> so suppose deadline for both these jobs is 4 -> in this case we can perform one job on day 4 (last day of its deadline) and will see if any of the day 3 or 2 or 1 is free and would do the other job on any of these days)

        for(int i =0 ; i < n ; i++) {
            int dead = jobs[i].second ;
            if(!booked[dead]) {
                booked[dead]=1 ; count++ ; profit += jobs[i].first ;
            }
            else{
                int j = dead-1;
                while(j >= 1) {
                    if(!booked[j]) {
                        // do this job on this day -> which is before deadline to maximise the profit
                        booked[j] = 1 ; count++ ; profit += jobs[i].first ; break ;
                    }
                    --j ;
                }
            }
        }
        
        return {count, profit} ;

    }
};