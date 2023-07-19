#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos , neg ;
	    for(int i =0 ; i < n ; i++) {
	        if(arr[i] >=0) {
	            pos.push_back(arr[i]) ;
	        }
	        else{
	            neg.push_back(arr[i]) ;
	        }
	    }
	    int i =0 , j =0 ;
	    int n1 = pos.size() , n2 = neg.size() , k =0 ;
	    while(i < n1 and j < n2) {
	        if(k%2 ==0) {
	            arr[k] = pos[i] ;
	            i++ ;
	        }
	        else{
	            arr[k] = neg[j] ;
	            j++ ;
	        }
	        k++;
	    }
	    while(i < n1) {
	        arr[k++] = pos[i++] ;
	    }
	    while(j < n2) {
	        arr[k++] = neg[j++] ;
	    }
	}
};