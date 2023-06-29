#include <bits/stdc++.h>
using namespace std;

// very easy problem -> just you need to understand the Scheduling Algo in Operating System and need to know how a non-preemptive table is made to solve such problems

// Note: Consider all process are available at time 0.

class Solution {
public:
    int solve(vector<int> &bt) {
        // code here
        sort(bt.begin() , bt.end()) ;

        int wt(0) , total(0) ; // wt denotes the waiting time for current element and total denotes the waiting time of all the elements summed up (since we need to find the average)
        for(int i =0 ;i < bt.size() ; i++) {
            total += wt ;
            int comp = wt + bt[i] ; // completion time for current element -> it would also be the waiting time for next element
            wt= comp ;
        }

        return total/bt.size() ; // average

    }
};