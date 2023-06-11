#include <bits/stdc++.h>
using namespace std ;

// the array is not sorted obviously (but we would be using binary search to solve the problem)
// remember the approach

class Solution
{
    public:
    int peakElement(int arr[], int n){
       // Your code here
       int low = 0 , high = n -1, mid ;
       while(low < high){
            mid= low + (high -low)/2 ;

            if(mid ==0){
                if(arr[mid] >= arr[mid+1]){return 0 ;}
                else{
                    return 1 ;
                }
            }
            else if(mid == n-1){
                if(arr[mid] >= arr[mid-1]){return n-1 ;}
                else{
                    return n-2 ;
                }
            }

            if(arr[mid] >= arr[mid+1] and arr[mid] >= arr[mid-1]){
                return mid ;
            }
            
            if(arr[mid-1] > arr[mid]){
                high = mid -1 ;
            }
            else{
                low = mid +1 ;
            }
       }

       return low ;

    }
};