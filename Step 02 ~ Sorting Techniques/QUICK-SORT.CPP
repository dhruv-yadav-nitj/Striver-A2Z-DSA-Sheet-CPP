#include <bits/stdc++.h>
using namespace std ;

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here

        if(low < high){
            int pivot_index = partition(arr, low, high) ;

            quickSort(arr, low, pivot_index-1) ; // left unsorted subarray
            quickSort(arr, pivot_index + 1 , high) ; // right unsorted subarray
        }

    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        // Your code here

        int pivot = arr[low] ; // assuming the first element as the pivot element

        int i = low , j = high;

        while(i < j){
            
            // finding the first element greater than pivot
            while(arr[i] <= arr[low] and i < high){
                i++ ;
            }

            // finding the first element smaller than pivot
            while(arr[j] > arr[low] and j > low){
                j-- ;                
            }

            // swap the elements such that the elements smaller than pivot get into left and greater element get to the right
            if(i < j){swap(arr[i], arr[j]) ;}

        }

        // place the pivot to its correct position
        swap(arr[low] , arr[j]) ; return j ; // j is the pivot_index

    }
};