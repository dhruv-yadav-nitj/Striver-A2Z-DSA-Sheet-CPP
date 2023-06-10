#include <bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int low = 0 , high = N-1 , mid ;
        while(low <= high){
            mid = low + (high - low)/2 ;

            if(A[mid] == Key){
                return true ;
            }

            if(A[low]==A[mid] and A[mid]==A[high]){
                low++ ; high-- ;
            }

            else if(A[low] <= A[mid]){
                if(Key >= A[low] and Key < A[mid]){
                    high = mid-1 ;
                }
                else{
                    low = mid+1; 
                }
            }
            else{
                if(Key > A[mid] and Key <= A[high]){
                    low = mid+1 ;
                }
                else{
                    high = mid -1 ;
                }
            }
        }
        return false ;

    }
};