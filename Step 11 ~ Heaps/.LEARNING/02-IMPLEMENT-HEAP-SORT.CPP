#include <bits/stdc++.h>
using namespace std;

void heapify (vector<int>&arr, int n, int i) {
    int largest = i , left = 2*i +1 , right = 2*i+ 2 ;
    if (left < n and arr[largest] < arr[left]) {
        largest = left ;
    }
    if(right < n and arr[largest] < arr[right]) {
        largest = right ;
    }
    
    if(largest != i) {
        swap(arr[largest] , arr[i]) ;
        heapify(arr, n, largest) ;
    }
}

vector<int> heapSort(vector<int> &arr, int n) {
    // Write your code here.

    // first we need to create a max heap out of this given array
    for(int i = n/2 ; i >=0 ; i--) {
        heapify(arr, n , i) ;
    }

    int size = n ;
    while(size > 1) {
        swap(arr[0] , arr[size-1]) ;
        size-- ;
        heapify(arr, size, 0) ;
    }

    return arr ;

}