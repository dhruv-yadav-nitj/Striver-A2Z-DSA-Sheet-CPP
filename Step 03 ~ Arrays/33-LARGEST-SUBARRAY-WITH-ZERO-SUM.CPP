#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int> &A, int n) {
        // Your code here

        unordered_map<int,int> mp ; int sum =0 , ans = 0 ;
        for(int i = 0; i < n; i++) {
            sum += A[i] ;
            if(sum ==0) {ans = i +1 ;}
            else if(mp.count(sum)) {
                ans= max(ans, i - mp[sum]) ;
            }
            else{
                mp[sum] = i ;
            }
        }

        return ans ;

    }
};