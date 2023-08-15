#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Intuition
/* This problem can be solved easily and efficiently by using the stack data structure as it is based on the Last in First out (LIFO) principle.

To find the next greater element we start traversing the given array from the right. As for the rightmost element, there is no other element at its right. Hence, we assign -1 at its index in the resultant array. Since this can be the next greater element (NGE) for some other element, we push it in the stack S. We keep checking for other elements. Let’s say we are checking for an element at index i. We keep popping from the stack until the element at the top of the stack is smaller than A[i]. The main intuition behind popping them is that these elements can never be the NGE for any element present at the left of A[i] because A[i] is greater than these elements. Now, if the top element of S is greater than A[i] then this is NGE of A[i] and we will assign it to res[i], where res is the resultant array. If the stack becomes empty then it implies that no element at the right of A[i] is greater than it and we assign -1. At last, we push A[i] in S. */

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) {

        stack<long long> st ; int i = n;
        while(i--){
            while(!st.empty() and st.top() <= arr[i]) {
                st.pop() ;
            }
            if(st.empty()) {
                st.push(arr[i]) ; arr[i]=-1;
            }
            else{
                long long temp=st.top() ;
                st.push(arr[i]); arr[i]= temp ;
            }
        }
        return arr ;
    }
};