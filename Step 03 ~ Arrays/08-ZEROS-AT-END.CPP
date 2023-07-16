#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i =-1 , j = 0 ;
	    while(j < n ) {
	        if(arr[j] != 0) {
	            i++ ; swap(arr[i] , arr[j]) ;
	        }
	        j++ ;
	    }
	}
};