#include <bits/stdc++.h>
using namespace std ;

// [MERGE SORT IS PROBABLY THE MOST USED OF SORTING TECH. IT IS USED IN ARRAY AS WELL AS IN LINKED LIST]
// [MANY PROBLEMS ARE BASED ON THIS CONCEPT OF MERGE SORT ONLY]
// [HARD PROBLEM ON THIS CONCEPT OF MERGE SORT]
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1 (Solution at the End of this Code)

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


// [MERGE TWO SORTED ARRAY WITHOUT USING EXTRA SPACE]
// the main intuition is to use the fact that the given arrays are sorted
class Solution {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        // code here
        int i = n -1 , j =0 ;
        while(i >=0 and j < m) {
            if(arr1[i] >= arr2[j]) {
                swap(arr1[i] , arr2[j]) ;
                i-- ; j++ ;
            }
            else{
                break ;
            }
        }
        sort(arr1,  arr1 + n) ; sort(arr2, arr2 + m) ;

    }
};