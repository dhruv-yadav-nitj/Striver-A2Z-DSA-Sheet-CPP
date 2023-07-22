#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        // CODE HERE

        int n = hand.size() ; if(n%groupSize != 0) {return false ;} // first check whether we can divide groups or not

        unordered_map<int,int> mp; priority_queue<int, vector<int> , greater<int>> pq ;
        for(auto it : hand) {
            if(!mp.count(it)) {
                mp[it] = 1 ;
                pq.push(it) ;
            }
            else{mp[it]++ ;}
        }
        
        while(!pq.empty()) {
            int mini = pq.top() ;
            while(mp[mini] > 0) {
                int j = mini + groupSize-1 ; int i = mini ;
                while(i <=j) {
                    if(mp.count(i)) {
                        mp[i]-- ; if(mp[i] == 0){
                            mp.erase(i) ;
                        }
                    }
                    else{
                        return false ;
                    }
                    i++ ;
                }
            }
            pq.pop() ;
        }

        return true ;

    }
};