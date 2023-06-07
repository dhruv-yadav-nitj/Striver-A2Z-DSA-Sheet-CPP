#include <bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here

        // since we know that xor operation is 1 when there is only 1 out of a and b, so this property can be used to solve this problem
        
        int c = (a ^ b) ;
        return __builtin_popcount(c) ;
        
    }
};