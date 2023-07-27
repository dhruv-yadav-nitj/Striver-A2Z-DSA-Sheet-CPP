#include <bits/stdc++.h>
using namespace std;

// using Kadane's Algorithm

/* 
Intuition : We can get max product by either multiplying two large positive numbers or by multiplying two small negative numbers -> so we need to store the maximum as well as minimum
*/

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        // CODE HERE

        int mini = nums[0] , maxi = nums[0] , ans = nums[0] ;
        for(int i =1 ;i < nums.size() ; i++) {

            int temp = max({nums[i], maxi*nums[i] , mini*nums[i]}) ;
            mini = min({nums[i] , maxi * nums[i] , mini * nums[i]}) ; maxi = temp ;
            ans = max(ans, maxi) ;
        }

        return ans ;

    }
};