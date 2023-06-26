#include <bits/stdc++.h>
using namespace std ;

// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// recursive solution
int solve1 (int index , vector<int> heights){

    if(index ==0){
        return 0 ;
    }

    int jump1=INT_MAX , jump2=INT_MAX ; // two jump costs --> jump1 when we jump only one step and jump2  when we jump 2 steps
    jump1 = abs(heights[index] - heights[index -1]) + solve1 (index - 1, heights) ;
    // jump cost consists of jumping from i to i -1 which is diff b/w heights and plus the further cost when we reached index i-1

    if(index > 1){ // we can't jump two steps when we are index 1
        jump2 = abs(heights[index] - heights[index - 2]) + solve1(index -2 , heights) ;
    }

    return min(jump1 , jump2) ;
}

// memoization
int solve2 (int ind , vector<int> height, vector<int>&dp){

    if(ind == 0){return 0 ;}

    if(dp[ind] != -1){
        return dp[ind] ;
    }

    int jump1 = INT_MAX , jump2 = INT_MAX ;
    jump1 = abs(height[ind] - height[ind-1]) + solve2(ind - 1 , height , dp) ;

    if(ind > 1){
        jump2 = abs(height[ind] - height[ind- 2]) + solve2(ind - 2 , height , dp) ;
    }

    return dp[ind] = min(jump1 , jump2) ;

}

// tabulation
int solve3 (int n , vector<int>&heights){

    vector<int> dp (n , -1) ; // dp array would be storing min cost to reach an index
    dp[0] = 0 ; dp[1] = abs(heights[1]- heights[0]) ;

    for(int i= 2; i < n ; i++){

        dp[i] = min( abs(heights[i] - heights[i-1]) + dp[i-1] , abs(heights[i] - heights[i-2]) + dp[i-2]) ;
    }

    return dp[n-1] ;

}

// space optimisation in tabulation
int solve4 (int n , vector<int> heights){
    if(n==1){return 0 ;}
    int prev2= 0 , prev1 = abs(heights[1] - heights[0]) ;

    for(int i=2; i < n; i++){

        int curr = min(abs(heights[i]- heights[i-1])+prev1 , abs(heights[i]-heights[i-2])+ prev2);
        prev2= prev1 , prev1 = curr ;

    }

    return prev1;
}

int frogJump(int n, vector<int> &heights){
    // Write your code here.

    // return solve1 (n-1 , heights) ; 

    // vector<int> dp (n , -1) ;
    // return solve2 (n-1 , heights , dp) ;

    // return solve3(n, heights) ;

    return solve4(n , heights) ;

}