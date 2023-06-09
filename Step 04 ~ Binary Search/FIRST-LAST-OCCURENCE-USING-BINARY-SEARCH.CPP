#include <bits/stdc++.h>
using namespace std ;

vector<int> find(int arr[], int n , int x )
{
    // code here
    
    int first_occ = -1, last_occ= -1 ;
    int low = 0 , high = n-1 , mid ;
    
    // finding first occ
    while(low <= high){
        int mid = low + (high -low)/2 ;
        
        if(arr[mid]==x){
            first_occ = mid ; high = mid-1 ;
        }
        else if(arr[mid] > x){
            high = mid -1 ;
        }
        else{
            low = mid +1 ;
        }
    }
    
    if(first_occ ==-1){
        return {-1, -1} ;
    }
    
    // finding last occ
    low= 0,  high =n-1 ;
    while(low <= high){
        int mid = low + (high -low)/2 ;
        
        if(arr[mid]==x){
            last_occ = mid ; low= mid +1 ;
        }
        else if(arr[mid] > x){
            high = mid-1 ;
        }
        else{
            low= mid+1 ;
        }
    }
    
    return {first_occ, last_occ} ;
    
}