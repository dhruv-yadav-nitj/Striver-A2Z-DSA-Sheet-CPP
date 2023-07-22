#include <bits/stdc++.h>
using namespace std;

// [HARD PROBLEM] [No way its a Medium Problem] -> its O(n) solution is yet more difficult for first-time intuition
// https://leetcode.com/problems/task-scheduler/submissions/

// [EXPLANATION]
// https://www.tutorialspoint.com/task-scheduler-n-cplusplus
// https://youtu.be/s8p8ukTyA2I

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        // code here
        unordered_map<char,int> mp ; priority_queue<int> pq ;
        for(auto it : tasks) {
            mp[it]++ ;
        }
        for(auto it :mp) {pq.push(it.second) ;}

        int ans =0 , cycle = n +1 ;
        while(!pq.empty()) {
            vector<int> temp ; int time = 0 , i =0 ;
            while(i < cycle and !pq.empty()) {
                temp.push_back(pq.top()) ;
                pq.pop() ; time++ ; i++ ;
            }

            for(int i =0 ; i < temp.size() ; i++) {
                --temp[i] ; if(temp[i] > 0) {pq.push(temp[i]) ;}
            }

            if(pq.empty()) {ans = ans + time ;}
            else{
                ans = ans + cycle ;
            }
        }
        return ans ;

    }
};