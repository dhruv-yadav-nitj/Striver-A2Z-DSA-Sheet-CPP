#include <bits/stdc++.h>
using namespace std ;

// xor property : a^a = 0 and 0^a = a

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
            
        int ans = 0 ;
        for(int i=0; i < n ;i++){
            ans = (ans ^ arr[i]) ;
        }
        
        return ans ;
        
    }
};