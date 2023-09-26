#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        // similar to finding fibonacci
        if(n <=1){return 1 ;}
        int a =1 , b = 1 ;
        // no of ways to reach 0th step from 0th step is 0 and no of ways to reach 0th step from 1th step is 1
        int ans (0) ;
        for(int i = 2; i <= n ; i++) {
            ans = a+ b ; b = a ; a = ans ;
        }
        return ans ;
    }
};