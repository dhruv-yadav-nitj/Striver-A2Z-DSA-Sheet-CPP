#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    void insertionSort(int arr[], int n){
        //code here

        for(int i =0 ;i < n; i++){
            int j = i;
            while(j >0 and arr[j-1] > arr[j]){
                int a = arr[j] ; arr[j] = arr[j-1] ; arr[j-1] = a ; --j ;
            }
        }
    }
};