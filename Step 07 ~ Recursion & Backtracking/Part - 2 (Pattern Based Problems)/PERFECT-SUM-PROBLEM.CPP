#include <bits/stdc++.h>
using namespace std ;

// approach #1 : using recursion --> gives TLE
// well we need not use a vector to store the subsequences with given sum as the problam asked only for count of such subsequences , so space optimisation is also possible here
class Solution{
	public:
    void recursion (int arr[], int index, int n , int sum, vector<int> temp , vector<vector<int>>&ans){
        // base condition
        if(index ==n){
            if(sum ==0){
                ans.push_back(temp) ;
            }
            return ;
        }

        if(arr[index] <= sum){
            temp.push_back(arr[index]) ;
            recursion(arr, index+1 , n , sum - arr[index] , temp , ans) ;

            temp.pop_back() ;
        }

        recursion(arr , index +1 , n , sum , temp , ans);
    }
	int perfectSum(int arr[], int n, int sum){
        // Your code goes here

        vector<vector<int>> ans;
        recursion(arr, 0 , n , sum , {} , ans) ;

        return ans.size() ;
	}	  
};