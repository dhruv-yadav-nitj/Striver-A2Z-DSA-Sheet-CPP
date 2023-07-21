#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        // code here
        priority_queue <int> pq ;
        for(auto it : nums) { pq.push(it) ;}
        int cnt = 1 ;
        while(cnt < k) {
            pq.pop() ; cnt++ ;
        }
        return pq.top() ;

    }
};