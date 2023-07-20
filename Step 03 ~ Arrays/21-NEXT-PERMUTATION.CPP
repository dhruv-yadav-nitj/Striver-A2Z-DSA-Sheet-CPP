#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-permutation/

// approach #1 [BRUTE FORCE] -> generate all possible permutations and compare for the next permutation

// approach #2 [STL] -> using next_permutation function
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        // code here
        next_permutation(nums.begin() , nums.end()) ;

    }
};

// approach #3
class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        // code here

        int pt =- 1 , n = nums.size() ;
        for(int i =n-2 ; i >=0 ; --i) {
            if(nums[i] < nums[i+1]) {
                pt = i ; break ;
            }
        }

        // if there's in no break point -> means the array is alreay sorted in decreasing order and we cant get any more lexicographically greater permutation -> so just reverse the array and return the smallest permutation (acc. to the ques)
        if(pt == -1) {
            reverse(nums.begin() , nums.end()) ; return ;
        }
        
        for(int i = n-1 ; i > pt ; --i) {
            if(nums[i] > nums[pt]) {
                swap(nums[i] , nums[pt]) ;
                reverse(nums.begin() + pt+1, nums.end()) ;
                return ;
            }
        }
    }
};