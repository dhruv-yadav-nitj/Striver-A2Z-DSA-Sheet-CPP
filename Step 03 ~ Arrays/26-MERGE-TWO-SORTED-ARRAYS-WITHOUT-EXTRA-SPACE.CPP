#include <bits/stdc++.h>
using namespace std;

// INTUITION : since we need to store the first n elements (if both of the arrays sorted together) in arr1 and other m elements in arr2 -> so we would try to transfer smaller elements from arr2 to arr1 and larger elements of arr1 to arr2
// this leads to two pointers -> one pointer starting from the end of arr1 and other starting from start of arr2

class Solution {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        // code here

        int i = n-1, j = 0 ;
        while(i >=0 and j < m) {
            if(arr2[j] <= arr1[i]) {
                swap(arr2[j] , arr1[i]) ;
                i-- , j++ ;
            }
            else{
                break ;
            }
        }
        // the swapping would lead to elements in random order in both the arrays -> so we need to sort those elements
        sort(arr1, arr1 + n) ; sort(arr2, arr2 + m);
    }
};