#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-consecutive-ones/1
// approach : we need to find the largest window having atmost k zeros

class Solution {
public:
    int longestOnes(int n, vector<int> &nums, int k) {
        // Code here
        int i =0 , j = 0 , count=0 , ans=0;
        while(j < n) {
            if(nums[j] ==0)  {
                count++ ;
            }
            if(count <= k) {
                j++ ;
            }
            else{
                ans = max(ans, j -i) ;
                if(nums[i] == 0) {
                    count--;
                }
                i++ ; j++ ;
            }
        }
        ans = max(ans, j -i) ; // for the last window -> this would not be dealt with in loop bcz at this moment j == n and we would end out of the loop
        return ans;

    }
};