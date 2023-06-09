#include <bits/stdc++.h>
using namespace std ;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
int count(int arr[], int n, int x) {
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
        return 0 ;
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
    
    return (last_occ - first_occ + 1) ;
	    
}
};