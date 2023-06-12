#include <bits/stdc++.h>
using namespace std ;

// did not applied binary search , but normal brute force approach
int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    
    int prev = a[0] , count =0 ;
    for(int i =1 ; i < n ; i++){
        if(a[i]-prev > 1){
            for(int j = prev +1 ; j < a[i] ; j++){
                count++ ; if(count == k){return j ;}
            }
        }
        prev = a[i] ;
    }
    
    return -1 ;
}