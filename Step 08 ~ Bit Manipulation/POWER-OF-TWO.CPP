#include <bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    

        return (__builtin_popcountll(n) == 1) ;
        // if it would be power of 2 then the number of set bits in its binary representation would be only 1

    }
};