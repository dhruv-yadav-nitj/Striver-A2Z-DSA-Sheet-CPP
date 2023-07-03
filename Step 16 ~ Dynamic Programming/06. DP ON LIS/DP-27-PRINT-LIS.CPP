#include <bits/stdc++.h>
using namespace std;

// tabulation approach of finding the LIS
class Solution {
public:
    int longestSubsequence(int n, int a[]) {
        // your code here

        vector<vector<int>> dp(n+1, vector<int> (n+1 , 0)) ;
        for(int i =n-1 ; i >= 0; i--) {
            for(int j = i -1 ; j >=-1 ; j--) {
                int take =0 , notTake = 0 ;
                
                // take
                if(j == -1 or a[i] > a[j]) {
                    take = 1 + dp[i +1][i+1] ;
                }
                notTake = dp[i+1][j +1] ;

                dp[i][j+1] =max(take, notTake) ;
            }
        }

        return dp[0][0] ;

    }
};

// Easiest Approach
// next approach to find the LIS

class Solution {
public:
    int longestSubsequence(int n, int a[]) {
        // your code here
        vector<int> dp (n, 1) ; // this dp array would store the length of the LIS ending at this particular index (if this element is part of the LIS)
        for(int i =1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(a[i] > a[j]) {
                    dp[i] = max(dp[i] , 1 + dp[j]) ;
                }
            }
        }

        return *max_element(dp.begin() , dp.end()) ;

    }
};

// printing the LIS
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here

        vector<int> dp(n , 1) ; vector<int> prevIndex (n, -1) ;
        for(int i =1 ;i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(arr[i] > arr[j]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j]+1 ;
                        prevIndex[i] = j ;
                    }
                }
            }
        }

        int lisLength = 0, endIndex = 0;
        for(int i=0 ; i < n ; i++) {
            if(dp[i] > dp[endIndex]) {
                lisLength =dp[i] ; endIndex =i ;
            }
        }

        vector<int> lis ;
        int i = endIndex ;
        while(i >=0){
            lis.push_back(arr[i]) ;
            i = prevIndex[i] ;
        }

        reverse(lis.begin(), lis.end()) ;
        return lis ;

    }
};

/* Approach

finding the size of LIS :

Create an array dp of the same length as the input array, where dp[i] will represent the length of the LIS ending at index i.
Initialize all elements of dp to 1, as the minimum LIS for any single element would be 1.
Iterate through the elements of the input array, starting from the second element (index 1).
For each element arr[i], iterate through all the elements before it (from index 0 to i-1).
For each element before arr[i], if arr[i] is greater than the previous element, update dp[i] to the maximum value of dp[i] and dp[j] + 1, where j represents the index of the previous element.
After iterating through the entire array, the maximum value in the dp array will be the length of the longest increasing subsequence.

printing the LIS :
Introduced a new vector prev_index to keep track of the previous index that contributes to the LIS ending at the current index. After calculating the LIS length, we find the last index (end_index) that contributes to the LIS. Then, we backtrack through the prev_index vector to construct the LIS and store it in the lis vector.

Finally, we reverse the lis vector to get the actual increasing subsequence. The main function prints the LIS in order.

*/