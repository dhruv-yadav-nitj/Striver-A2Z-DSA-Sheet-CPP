#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/number-of-inversions_6840276?utm_

/* 
Approach : https://www.youtube.com/watch?v=AseUmwVNaoY (very nice explanation)
*/

int cnt = 0; // answer variable
void merge (vector<int>&a, int l, int mid, int r) {

    int i = l , j= mid +1 ;
    while(i <= mid and j <= r) {

        if(a[i] > a[j])  {
            cnt += (mid -i +1) ;
            j++ ;
        }
        else{
            i++ ;
        }
    }

    // merge the both arrays into some sorted form

    i = l , j = mid +1 ; vector<int> temp ;
    while(i <= mid and j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]) ; i++ ;
        }
        else{
            temp.push_back(a[j]) ; j++ ;
        }
    }

    while(i <= mid) {
        temp.push_back(a[i]) ; i++ ;
    }

    while(j <= r) {
        temp.push_back(a[j]) ; j++ ;
    }

    for(int i = l ; i <= r ; i++) {
        a[i] = temp[i-l] ;
    }
}

void divide (vector<int>&a, int l , int r)  {

    if (l >= r) {return ;}

    int mid= l + (r - l)/2 ;

    divide (a, l , mid) ; divide (a, mid +1 , r) ;

    merge(a, l, mid, r) ;

}

int numberOfInversions(vector<int> &a, int n) {
    // Write your code here.
    
    divide (a, 0 , n-1) ; return cnt ;

}



// GFG VERSION
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
public:

    long long cnt =0 ;

    void merge (long long arr[], long long low, long long mid, long long high) {

        long long i = low, j = mid +1 ; vector<long long> temp ;

        while(i <= mid and j <= high) {

            if(arr[i] > arr[j]) {
                cnt += (mid - i +1) ;
                temp.push_back(arr[j]) ; j++ ;
            }
            else{
                temp.push_back(arr[i]) ; i++ ;
            }
        }

        while(i <= mid) {temp.push_back(arr[i++]) ;}
        while(j <= high) {temp.push_back(arr[j++]) ;}

        for(long long k = low; k <= high;  k++) {
            arr[k] = temp[k - low] ;
        }
    }

    void divide (long long arr[], long long n, long long l, long long r) {

        if(l >= r) {return ;} // when only single element is left
        long long mid = l + (r-l)/2 ;
        divide(arr, n, l, mid) ; divide(arr, n, mid +1 , r) ;

        merge(arr, l, mid, r) ;
    }

    long long int inversionCount(long long arr[], long long N) {
        // Your Code Here

        divide(arr, N, 0, N-1) ; return cnt ;

    }

};