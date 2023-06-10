#include <bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here

        int low = l , high = h , mid ;
        while(low <= high){

            mid = low + (high -low)/2 ;
            if(A[mid]== key){
                return mid ;
            }
            else if(A[low] <= A[mid]){
                // means left part of the array is sorted
                // if key lies b/w the range of left sorted array then shift the current range there
                if(key >= A[low] and key <= A[mid]){
                    high = mid-1 ;
                }
                else{
                    low = mid +1 ;
                }
            }
            else{
                // means right part of the array is sorted
                // if key lies b/w the range of right sorted array then shift the current range there
                if(key >= A[mid] and key <= A[high]){
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