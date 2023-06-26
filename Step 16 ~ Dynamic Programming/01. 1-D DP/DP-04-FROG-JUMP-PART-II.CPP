
// read problem statement from :-
// https://atcoder.jp/contests/dp/tasks/dp_b
// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/

#include <bits/stdc++.h>
using namespace std ;

// simple recursion solution
int solve1 (int index, vector<int>heights, int k){

    if(index == 0){return 0 ;}

    int  mini = INT_MAX ;
    for(int i=1 ; i <= k; i++){

        if(index - i >=0){
            int jump_cost = abs(heights[index]-heights[index - i]) + solve1(index -i , heights , k) ;

            mini = min(mini , jump_cost) ;
        }
    }
    return mini ;
}

// memoization solution
int solve2 (int index , vector<int>heights , int k , vector<int>&dp){
// dp[i] would be storing the min cost of jump from index i
    if(index== 0){return 0 ;}

    if(dp[index]!= -1){
        return dp[index] ;
    }

    int mini = INT_MAX ;
    for(int i=1 ; i <= k ; i++){
        if(index - i >= 0){

            int jump_cost = abs(heights[index]-heights[index-i]) + solve2(index-i , heights , k, dp) ;
            mini = min(mini , jump_cost) ;

        }
    }
    return dp[index] = mini ;
}

// tabulation method
int solve3 (int n, vector<int> heights, int k){
    
    vector<int> dp (n+1, -1) ;

    dp[0] = 0 ;
    for(int i = 1 ; i < n;i++){
        int mini = INT_MAX ;
        for(int j = 1 ; j <= k; j++){

            if(i - j >= 0){
                int jump_cost = abs(heights[i]- heights[i-j])+ dp[i-j] ;
                mini= min(mini , jump_cost) ;
            }
        }
        dp[i] = mini ;

    }
    return dp[n-1] ;

}

int frogJump(int n, vector<int> &heights, int k){
    // Write your code here.
    

}