#include <bits/stdc++.h>
using namespace std ;

class Solution{
	public:
	int NthRoot(int n, int m){
	    // Code here.

        int low  =0 , high = m , mid , ans=-1 ;
        while(low <= high){
            mid = low + (high-low)/2 ;
            if(pow(mid , n) <= m){
                ans = mid ; low = mid +1 ;
            }
            else{
                high = mid -1 ;
            }
        }

        if(pow(ans, n) != m){
            return -1 ;
        }
        else{
            return ans ;
        }
	}  
};