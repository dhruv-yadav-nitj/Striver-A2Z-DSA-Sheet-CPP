#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq ; int i =0, n = nums.size() ;
        while(i < k) {pq.push({nums[i], i}); i++;}
        vector<int> ans ; ans.push_back(pq.top().first) ;
        for( ; i < n ; i++) {

            while(!pq.empty() and pq.top().second <= i-k) {
                pq.pop() ;
            }
            pq.push({nums[i], i}) ;
            ans.push_back(pq.top().first) ;
        }
        return ans ;
    }
};

// Approach #2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq ; vector<int> ans ; int n= nums.size() ;
        for(int i=0; i < n; i++) {

            while(!dq.empty() and dq.front() <= i-k) {
                dq.pop_front() ;
            }

            while(!dq.empty() and nums[dq.back()] < nums[i]) {
                dq.pop_back() ;
            }

            dq.push_back(i) ;
            if(i >= k -1){ans.push_back(nums[dq.front()]) ;}
        }
        return ans;        
    }
};

// Approach #3
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int index=0 ; vector<int> ans ;
        for(int i=k-1 ; i< nums.size(); i++){
            // index = 0 ;
            int maxi = INT_MIN ;
            while(index <= i-k){
                index++ ;
            }
            while(index <= i){
                maxi = max(maxi, nums[index]) ; index++ ;
            }
            ans.push_back(maxi) ;
        }
        return ans ;
    }
};