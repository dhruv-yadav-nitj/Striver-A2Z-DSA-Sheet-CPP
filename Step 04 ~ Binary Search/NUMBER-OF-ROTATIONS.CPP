#include <bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int n){
    // code here

    // we need to find the min element in rotated sorted array --> its index will determing the number of rotations
    // take the example of  4 5 1 2 3 --> in this case point of rotation is index 2 and that's also the min element so using the index = 2 we can tell that it was rotated 2 times left

    int mini=INT_MAX , mini_index ;
    int low=0 , high = n -1 , mid ;
    while(low <= high){

        mid = low + (high -low)/2 ;
        if(arr[low] <= arr[mid]){
            // means the left part is sorted
            mini= min(mini, arr[low]) ;
            if(mini == arr[low]){
                mini_index= low ;
            }
            low = mid +1 ; // move to the right part ho skta hain udhar isase bhi min element ho
        }
        else{
            mini = min(mini,  arr[mid]) ;
            if(mini == arr[mid]){
                mini_index = mid ;
            }
            high = mid -1 ;
        }
    }

    return mini_index ;

}