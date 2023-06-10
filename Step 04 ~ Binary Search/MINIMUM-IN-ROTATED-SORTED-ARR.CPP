#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n){
    // your code here

    int mini = INT_MAX ;
    int low = 0 , high = n-1 , mid ;

    while(low <= high){
        mid = low + (high -low)/2 ;

        if(arr[low] <= arr[mid]){

            // means left part is sorted
            mini = min(mini, arr[low]) ;
            // update the mini with left most element of this sorted part and then move to the right
            low = mid +1 ;
        }
        else{
            // means right part is sorted
            mini= min(mini , arr[mid]) ;
            // update the mini with this element and move to the left part
            high = mid-1 ;
        }
    }

    return mini ;

}