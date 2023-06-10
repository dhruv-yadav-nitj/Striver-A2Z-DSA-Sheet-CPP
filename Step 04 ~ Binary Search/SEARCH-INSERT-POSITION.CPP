#include <bits/stdc++.h>
using namespace std ;

/* 
assume that if k is greatest of all the numbers then it should be inserted at Nth position so one of the possible ans is N so , take ans = N initially
now apply binary search
if arr[mid] < k --> we need to move forward, bcz we cant insert k at some index where the number is small before hand
if arr[mid] > k --> then this mid can be one of the possible ans so take ans = mid and high = mid-1
if arr[mid] = k --> simply return mid
*/

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int K = k ;
        int low = 0 , high = N-1 , ans = N , mid;
        while(low <= high){
            mid= low + (high -low)/2 ;
            if(Arr[mid] == K){
                return mid ;
            }
            else if(Arr[mid] < K){
                low = mid+1 ;
            }
            else{
                ans = mid ; 
                high = mid -1 ;
            }
        }

        return ans ;
        
    }
};