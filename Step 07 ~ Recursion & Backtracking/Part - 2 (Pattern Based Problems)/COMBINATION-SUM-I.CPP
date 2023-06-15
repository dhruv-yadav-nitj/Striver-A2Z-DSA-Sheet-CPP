#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void recursion (vector<int> arr, int index, int sum , vector<int> temp, vector<vector<int>>&ans){
        if(index == arr.size()){
            if(sum == 0){
                ans.push_back(temp) ;
            }
            return ;
        }

        // pick
        if(arr[index] <= sum){
            temp.push_back(arr[index]) ;
            recursion(arr, index, sum - arr[index] , temp , ans) ;

            // backtrack
            temp.pop_back() ;
        }

        // not-pick
        recursion(arr, index +1 , sum , temp , ans) ;
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        sort(A.begin(), A.end());
        // since the given array can contain duplicates we need to remove the duplicates in order to get unique subsequences

        // removing the duplicates using c++ stl in sorted vector
        A.erase(unique(A.begin(), A.end()), A.end()) ;
        
        vector<vector<int>> ans ;
        recursion(A, 0 , B , {} , ans) ;

        return ans ;
    }
};