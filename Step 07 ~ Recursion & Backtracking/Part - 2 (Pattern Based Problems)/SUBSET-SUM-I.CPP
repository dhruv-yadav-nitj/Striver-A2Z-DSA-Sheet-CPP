#include <bits/stdc++.h>
using namespace std ;

// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
// easy problem based directly on pick and not pick technique

class Solution
{
public:
    void recursion (vector<int> arr, int index , int N , int sum, vector<int>&ans){
        if(index == N){
            ans.push_back(sum) ; return ;
        }

        // pick
        recursion(arr, index +1 , N , sum + arr[index], ans) ;

        // not pick
        recursion(arr, index +1 , N , sum , ans) ;

    }
    vector<int> subsetSums(vector<int> arr, int N){
        // Write Your Code here
        
         vector<int> ans ;
         recursion(arr, 0, N , 0 , ans) ;
         sort(ans.begin() , ans.end()) ;
         return ans ;
    }
};