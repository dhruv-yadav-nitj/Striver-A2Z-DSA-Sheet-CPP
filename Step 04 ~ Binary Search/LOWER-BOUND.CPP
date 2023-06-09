#include <bits/stdc++.h>
using namespace std ;

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        // your code here

        // what is lower bound or floor : Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing). remember lower than or equal to

        long long low = 0 , high = n-1 , mid, lower_bound =-1 ;
        while(low <= high){
            mid = low + (high -low)/2 ;
            if(v[mid] <= x){
                lower_bound = mid ;
                low = mid+1 ;
            }
            else{
                high = mid-1 ;
            }
        }

        return lower_bound ;
    }
};