#include <bits/stdc++.h>
using namespace std ;

class Solution {

  public:
    void recursion (vector<int>nums, int index, vector<int> temp , vector<vector<int>>&ans){
        
        // since we have to consider all the possible subsets so we can push the temp no matter what its index is currently
        ans.push_back(temp);
        
        for(int i=index ; i < nums.size() ; i++){
            if(i != index and nums[i] == nums[i-1]){
                continue ;
            }
            
            
            temp.push_back(nums[i]) ;
            recursion (nums , i+1, temp , ans) ;
            
            // backtrack and not pick
            temp.pop_back() ;
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin() , nums.end()) ;
        vector<vector<int>> ans ;
        recursion(nums , 0 , {} , ans) ;
        return ans ;
    }
};