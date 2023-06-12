#include <bits/stdc++.h>
using namespace std ;

// Intuition : simply applied the concept of problem Merge two sorted Arrays / Linked List

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        // your code here
        
        int i = 0 , j= 0 , index = 0 ;
        while(i < n and j < m){
            if(arr1[i] <= arr2[j]){
                index++ ;
                if(index == k){
                    return arr1[i] ;
                }
                i++ ;
            }
            else{
                index++ ;
                if(index == k){
                    return arr2[j] ;
                }
                j++ ;
            }
        }
        
        while(i < n){
            index++ ;
                if(index == k){
                    return arr1[i] ;
                }
                i++ ;
        }
        
        while(j < m){
            index++ ;
                if(index == k){
                    return arr2[j] ;
                }
                j++ ;
        }
        
        
        return -1 ;
        
    }
};