#include <bits/stdc++.h>
using namespace std;

// done myself in first attempt without any help (writing this to remind myself when revising again)

class Solution{
public:
    void recursion (int start,  int N , int k , int size ,int sum, vector<int> temp , vector<vector<int>>&ans){
        if(size == k){
            if(sum == N){
                ans.push_back(temp) ;
            }
            return ;
        }


        for(int i = start ; i <= 9; i++){
            
            if(sum + i<= N){
                temp.push_back(i);
                recursion(i +1 , N , k , size+1 , sum + i , temp , ans) ;

                // backtrack
                temp.pop_back() ;
            }
            else{
                break ;
            }
        }

        // return;

    }
    vector<vector<int>> combinationSum(int K, int N){
        // code here

        vector<vector<int>> ans;
        recursion(1, N , K , 0 , 0 , {} , ans) ;
        return ans ;
    }
};