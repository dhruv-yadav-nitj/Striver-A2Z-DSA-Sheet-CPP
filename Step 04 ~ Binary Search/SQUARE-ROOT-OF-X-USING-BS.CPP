#include <bits/stdc++.h>
using namespace std ;

// apply binary search in range

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        
        long long low = 0 , high = x , mid, ans ;
        while(low <= high){
            mid = low + (high - low)/2 ;
            if(mid*mid <= x){
                ans = mid ; low = mid+1 ;
            }
            else{
                high = mid -1 ;
            }
        }
        
        return ans ;
        
    }
};