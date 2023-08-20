#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-subarray-ranges/

// O(n^2)
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        
        long long ans =0 ; int n = nums.size();
        for(int i=0; i < n; i++) {
            int maxi = nums[i], mini = nums[i] ;
            for(int j=i+1; j< n ; j++) {

                maxi = max(maxi, nums[j]) ;
                mini = min(mini, nums[j]) ;

                ans += maxi - mini ;
            }
        }
        return ans ;
    }
};

// using stack solution
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        vector<int> left_greater(n,-1),right_greater(n,n);
        vector<int> left_smaller(n,-1),right_smaller(n,n);
        stack<int> s1,s2,s3,s4;
        for(int i=0;i<n;i++){
            // kitne logo k lie next greater element nums[i] hain
            // from left to right
            while(!s1.empty() and nums[s1.top()]<nums[i]){
                right_greater[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            // kitne logo k lie just previous greater element nums[i] hain
            // from right to left
            while(!s2.empty() and nums[s2.top()]<=nums[i]){
                left_greater[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        for(int i=0;i<n;i++){
            // kitne logo k lie next smaller element nums[i] hain 
            // from left to right
            while(!s3.empty() and nums[s3.top()]>nums[i]){
                right_smaller[s3.top()] = i;
                s3.pop();
            }
            s3.push(i);
        }
        for(int i=n-1;i>=0;i--){
            // kitne logo k lie just previous smaller element nums[i] hain
            // from right to left
            while(!s4.empty() and nums[s4.top()]>=nums[i]){
                left_smaller[s4.top()] = i;
                s4.pop();
            }
            s4.push(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long maxi = (right_greater[i] - i) * (i - left_greater[i]);
            long long mini = (right_smaller[i] - i) * (i - left_smaller[i]);
            ans += (maxi*nums[i]);
            ans -= (mini*nums[i]);
        }        
        return ans;
        
    }
};