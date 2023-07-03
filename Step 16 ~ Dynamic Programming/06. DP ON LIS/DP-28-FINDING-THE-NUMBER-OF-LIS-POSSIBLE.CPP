#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int NumberofLIS(int n, vector<int> &arr) {
        // Code here
        vector<int> dp (n, 1) , count(n, 1) ;
        for(int i =1 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(arr[i] > arr[j]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] =dp[j] + 1 ;
                        count[i] = count[j] ;
                    }
                    else if(dp[i] == dp[j] + 1) {
                        count[i] += count[j] ;
                    }
                }
            }
        }

        int maxLIS = *max_element(dp.begin() , dp.end()) ;
        int ans = 0 ;
        for(int i = 0; i < n ; i++) {
            if(dp[i] == maxLIS) {
                ans += count[i] ;
            }
        }
        return ans ;

    }
};