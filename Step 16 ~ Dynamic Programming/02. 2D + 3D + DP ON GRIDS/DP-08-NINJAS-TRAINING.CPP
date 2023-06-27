#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // step 1 : recursion
    int recursion (vector<vector<int>>&points, int day , int last){
        
        // base condition
        if(day == 0){

            // consider the maximum point we can earn on the day 0 exluding the activity we did on day 1
            int maxi = INT_MIN ;
            for(int i =0; i < 3 ; i++){
                if(i != last){
                    maxi = max(maxi , points[0][i]) ;
                }
            }

            return maxi ;
        }

        int maxi = INT_MIN ;
        for(int i =0; i < 3 ; i++){
            if(i != last){
                maxi = max(maxi , points[day][i] + recursion(points, day -1 , i));
            }
        }

        return maxi ;

    }

    // step 2 : memoization
    // Time ~ O(N*3) there are N days and we are running the loop for 3 times for each day
    int memoization (vector<vector<int>>&points, int day , int last, vector<vector<int>>&dp){
        // base condition

        if(dp[day][last] != -1){
            return dp[day][last] ;
        }

        if(day == 0){

            // consider the maximum point we can earn on the day 0 exluding the activity we did on day 1
            int maxi = INT_MIN ;
            for(int i =0; i < 3 ; i++){
                if(i != last){
                    maxi = max(maxi , points[0][i]) ;
                }
            }

            return dp[day][last] = maxi ;
        }

        // if not present in the dp array

        int maxi= INT_MIN ;
        for(int i=0; i < 3 ; i++){
            if(i != last){
                maxi = max(maxi , points[day][i] + memoization(points, day-1, i, dp)) ;
            }
        }

        return dp[day][last] = maxi ;
    }

    // step 3: tabulation
    int tabulation (vector<vector<int>>&points , int n){

        vector<vector<int>> dp (n , vector<int> (4, 0)) ;

        // take day 0 into account
        // we can assume that the last activity was 0th activity
        dp[0][0] = max(points[0][1], points[0][2]) ;
        dp[0][1] = max(points[0][0], points[0][2]) ;
        dp[0][2] = max(points[0][1], points[0][0]) ;
        dp[0][3] = max({points[0][1], points[0][2], points[0][0]}) ; // that's the trick to take max of more than 2 elements

        for(int day= 1 ; day < n ; day++){

            for(int last = 0 ; last < 4; last++){
                
                for(int curr = 0 ; curr <= 2 ; curr++){
                    
                    if(curr != last){
                        dp[day][last] = max(points[day][curr] + dp[day-1][curr], dp[day][last]) ;
                    }

                }

            }
        }
        return dp[n-1][3] ;
    }

    int maximumPoints(vector<vector<int>> &points, int n){
        // Code here

        return recursion(points, n -1 , -1) ;

        // point to be noted : we are taking dp of size 4 columns and not 3 and is passing the last as 3 (do a dry run and understand) --> bcz if we take size as 3 (which is needed) and pass the last as -1 then from which hell we would bring dp[n-1][-1] (which is where we would be storing the things in memoization function) there's no such thing
        vector<vector<int>> dp (n , vector<int> (4 , -1)) ;
        return memoization(points, n-1 , 3, dp) ;

        return tabulation(points, n) ;

    }
};

// Revision
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int recursion (vector<vector<int>>&points , int day , int last) {

        // base condition
        if (day < 0) {
            return 0 ;
        }

        int maxi = INT_MIN ;
        for(int i =0 ; i < 3 ; i++) {
            // ith activity choose but it should not be the one chosen last day also
            if(i != last) {
                maxi =max(maxi , points[day][i] + recursion(points , day -1 , i));
            }
        }

        return maxi ;
    }

    int memoization (vector<vector<int>>&points , int day , int last, vector<vector<int>>&dp) {

        // base condition
        if (day < 0) {
            return 0 ;
        }

        if(dp[day][last] != -1) {
            return dp[day][last] ;
        }

        int maxi = INT_MIN ;
        for(int i =0 ; i < 3 ; i++) {
            // ith activity choose but it should not be the one chosen last day also
            if(i != last) {
                maxi =max(maxi , points[day][i] + memoization(points , day -1 , i, dp));
            }
        }

        return dp[day][last] = maxi ;
    }
    
    int maximumPoints(vector<vector<int>> &points, int n){
        // Code here
        
        // since matrix would be 0-based indexing -> so first day would be 0 and last day would be n -1
        // return recursion(points, n -1 , -1) ;

        // now there are two factors which decide which activity to choose -> day and last
        vector<vector<int>> dp (n , vector<int> (4, -1)) ;
        return memoization(points, n-1 , 3, dp) ;

    }
};