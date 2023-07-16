#include <bits/stdc++.h>
using namespace std;

// approach #1 : rotate the array by 1 place but d number of times

class Solution {
public:
    void rotateSingle (int arr[], int n) {
        int temp = arr[0] ;
        for(int i =1 ; i < n ; i++) {
            arr[i-1] = arr[i] ;
        }
        arr[n-1]= temp ;
    }
    void rotateArr(int arr[], int d, int n) {
        // code here
        while(d--) {
            rotateSingle(arr, n) ;
        }
    }
};

// approach #2 : optimised approach
class Solution {
public:
    void reverse (int arr[], int i , int j) {
        while(i <= j) {
            swap(arr[i] , arr[j]) ; i++ ; j-- ;
        }
    }
    void rotateArr(int arr[], int d, int n) {
        // code here

        // case 1: when the rotated array would be same as the initial array
        d %= n; // -> suppose n = 5 and we are asked to rotate the array 5 times -> this would lead to no change in the initial array
        if(d==0) {
            return ;
        }

        // reverse whole array -> reverse first n-d elements -> reverse next d elements
        reverse(arr, 0, n-1) ;
        reverse(arr, 0 , n-d-1) ; reverse(arr, n-d , n-1) ;
        
    }
};