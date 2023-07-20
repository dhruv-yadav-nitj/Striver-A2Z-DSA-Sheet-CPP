#include <bits/stdc++.h>
using namespace std;

// also see the problem #10

// https://leetcode.com/problems/subarray-sum-equals-k/

// [BRUTE FORCE] -> check all the subarray -> O(n^2)
// [OPTIMISED] -> using prefix sum (remember that whenever we have to do some array problem in O(n) time -> try to do in Prefix Sum)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0 , cnt =0 ;
        unordered_map <int,int> mp ;
        for(int i =0 ; i < nums.size() ; i++) {
            prefixSum += nums[i] ;
            if(prefixSum == k) {cnt++ ;}
            if(mp.count(prefixSum - k)) {
                cnt = cnt + mp[prefixSum - k] ;
            }
            mp[prefixSum]++ ;
        }
        return cnt ;
    }
};