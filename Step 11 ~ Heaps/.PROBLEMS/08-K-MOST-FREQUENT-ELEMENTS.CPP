#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // CODE HERE

        unordered_map<int,int> mp ; for(auto it : nums) {mp[it]++ ;} // store the frequency of each element of nums
        
        // insert all the {frequency, element} pair in a vector
        vector<pair<int,int>> vec; for(auto it: mp) {vec.push_back({it.second, it.first}) ;}

        sort(vec.begin() , vec.end(), greater()) ; // sort the vec according to the frequency of elements

        vector<int> ans ; for(int i =0 ; i < k ; i++) {ans.push_back(vec[i].second) ;}

        return ans ;

    }
};

// Heap Approach
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp ;
        for(auto it : nums) {mp[it]++ ;}

        priority_queue<pair<int,int>> pq ; // max-heap
        for(auto it : mp) {pq.push({it.second, it.first}) ;}

        vector<int> ans ;
        while(k) {
            ans.push_back(pq.top().second) ;
            pq.pop() ; --k ;
        }

        return ans ;
    }
};