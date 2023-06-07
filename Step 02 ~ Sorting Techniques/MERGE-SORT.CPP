#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    void merge(int arr[], int l, int m, int r){ // used to merge the 2 halves of the array
         // Your code here

         vector<int> temp ;
         int left = l , right = m +1 ;

         while(left <= m and right <= r){
            
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]) ;
            }
            else{
                temp.push_back(arr[right++]) ;
            }
         }

        //  copy the left-out elements
        while(left <= m){
            temp.push_back(arr[left]) ; left++ ;
        }
        while(right <= r){
            temp.push_back(arr[right++]) ;
        }

        // transfer the elements of temp into arr within range low to high
        for(int i = l ; i <= r ; i++){
            arr[i] = temp[i - l] ;
        }

    }
    void mergeSort(int arr[], int l, int r){ // used to divide the array into 2 parts
        //code here

        if(l >= r){
            return ;
        }
        int mid = (l+ r) /2 ;
        mergeSort(arr , l , mid) ; // left half
        mergeSort(arr, mid +1 , r) ; // right half

        merge(arr, l , mid , r) ;
    }
};