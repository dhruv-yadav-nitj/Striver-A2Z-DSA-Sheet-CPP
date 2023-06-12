#include <bits/stdc++.h>
using namespace std ;

// approach #1 : using merging of two arrays concept
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        
        int i =0 , j= 0;
        vector<int> merge ;
        while(i < array1.size() and j < array2.size()){
            if(array1[i] <= array2[j]){
                merge.push_back(array1[i++]) ;
            }
            else{
                merge.push_back(array2[j++]) ;
            }
        }
        
        while(i < array1.size()){
            merge.push_back(array1[i++]) ;
        }
        
        while(j < array2.size()){
            merge.push_back(array2[j++]) ;
        }
        
        int n = merge.size() ;
        if(n%2 == 0){
            return (merge[n/2] + merge[(n/2) -1 ])/2.0 ;
        }
        else{
            return merge[n/2] ;
        }
    
    }
};

// approach #2 : Similar to the naive approach (and the concept used in kth element of two sorted arrays problem), instead of storing the final merged sorted array, we can keep a counter to keep track of the required position where the median will exist. First, using the median formula, get a position where the median will exist. Then, follow the above approach and instead of storing elements in another array, we will increase the counter value. When the counter value is equal to the median positions, return the element.