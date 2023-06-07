#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n){
        // Your code here  

        for(int i = n-1 ; i >= 0 ; i--){

            for(int j = 0 ; j < i ; j++){
                if(arr[j +1] < arr[j]){
                    swap(arr[j] , arr[j+1]) ;
                }
            }
        }
    }
};