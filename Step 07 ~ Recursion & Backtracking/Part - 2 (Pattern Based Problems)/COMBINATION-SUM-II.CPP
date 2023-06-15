
// How is it different from Combination Sum I ?
// In Part 1 we were asked to consider only unique subsequences and it was given that we can use an element as many number of times as we want --> these two things allowed us to delete all the duplicates from the vector given
// But in Part 2 we are asked to consider unique subsequence but we can use an element only once --> so we cant delete any element here as if we would delete all the duplicates then we would not know how many times did we need to take a certain unique element
// do some dry run and you will understand more clearly
// Eg :
/*
n = 5
arr[] = 8 1 8 6 8
target = 12
*/

#include <bits/stdc++.h>
using namespace std ;

// well we can use unordered set to store the unique combinations --> but that approach would give us tle so we would slightly modify the process we used in Part I of this problem

class Solution{
public:
    void recursion (vector<int> arr, int index , int target, vector<int> temp,  vector<vector<int>>&ans){
        // base condition
        if(target == 0){
            ans.push_back(temp) ;
            return ;
        }
        // here we have not added if(index == n) {return ;} in the base condition bcz that work is done by break statement in the for loop --> i.e., whenever some big element would come we woudl return from there only

        for(int i =index ; i < arr.size() ; i++){

            // if the element is repeated
            if(i != index and arr[i] == arr[i-1]){
                continue;
            }
            
            // no need to check further if the curr element is greater than target since the array is sorted
            if(arr[i] > target){break ;}

            temp.push_back(arr[i]) ;
            recursion(arr, i+1 , target-arr[i], temp , ans) ;

            // backtrack
            temp.pop_back();
        }

        return ;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        // Write your code here

        vector<vector<int>> ans ;
        sort(candidates.begin() , candidates.end()) ;

        recursion(candidates, 0, target , {} , ans) ;
        return ans ;
    }
};