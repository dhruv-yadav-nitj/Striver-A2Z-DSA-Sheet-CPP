#include <bits/stdc++.h>
using namespace std ;

// approach #1 :using xor property --> Time ~ O(n)

// approach #2 : since the arr is sorted we can think of some binary search solution

class Solution
{
  public:
    int findOnce(int arr[], int n){
        //code here.

        int low = 0 , high = n-1 , mid ;
        while(low <= high){
            mid = low + (high -low)/2 ;
            
            // case 1 : if the target is found --> means both the neighbours are different from target
            if(arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]){
                return arr[mid] ;
            }
            
            // if the mid is odd --> if the mid-1 element is same this means we have to shift towards right side else on the left side
            if(mid&1==1){
                // if mid is odd
                if(arr[mid-1]==arr[mid]){low = mid+1 ;}
                else{
                    high = mid -1 ;
                }
            }
            // means the mid is even --> if the mid+1 element is same this means we have to shift towards right else left side mein shift ho
            else{
                if(arr[mid] == arr[mid+1]){
                    low = mid+1 ;
                }
                else{
                    high = mid-1 ;
                }
            }
        }

        return -1 ;
        
    }
};