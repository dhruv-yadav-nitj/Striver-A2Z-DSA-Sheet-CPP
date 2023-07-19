#include <bits/stdc++.h>
using namespace std;

// brute force : sort the arr and then count the consecutive element
// approach : use unordered set to store all the elements of the array -> 

class Solution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        // Your code here

        unordered_set<int> st ;
        for(int i =0 ; i < N ; i++) {
            st.insert(arr[i]) ;
        }

        int maxi = 0 ;
        for(int i =0 ; i < N ; i++) {
            // if we have not encountered this particular element before already -> then only traverse through it -> bcz why we would traverse through the same element again and again
            if(!st.count(arr[i] - 1)) {
                int count =1 , fwd = arr[i] +1 ;
                while(st.find(fwd) != st.end()) {
                    count++ ; fwd++ ;
                }
                maxi = max(maxi, count) ;
            }
        }
        return maxi ;

    }
};