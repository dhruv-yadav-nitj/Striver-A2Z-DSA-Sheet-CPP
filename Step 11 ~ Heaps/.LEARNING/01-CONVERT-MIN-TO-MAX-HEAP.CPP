#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/convert-min-heap-to-max-heap_1381084?leftPanelTab=0

void heapify (vector<int>&arr, int n, int i) {
    int largest = i, left = 2*i +1 , right = 2*i + 2 ; // check for left and right child
    if(left < n and arr[largest] < arr[left])  {
        largest = left ;
    }
    if(right < n  and arr[largest] < arr[right]) {
        largest = right ;
    }
    // if the child has value greater than the parent node -> swap them and then apply heapify algorithm on the new largest node
    if(largest != i) {
        swap(arr[i] , arr[largest]) ;
        heapify(arr, n, largest) ;
    }
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	for(int i = n/2 ; i >= 0 ; i--) {
		heapify(arr, n, i) ;
	}
	return arr ;
}