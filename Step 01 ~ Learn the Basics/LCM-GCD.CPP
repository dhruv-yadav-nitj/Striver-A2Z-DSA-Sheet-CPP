#include <bits/stdc++.h>
using namespace std ;

// gcd (a, b) = gcd(b, a%b)

class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
            
        long long gcd = __gcd (A, B) ; long long lcm = (A*B)/gcd ;
        return {lcm , gcd} ;
        
    }
};