#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

// appraoach#1 : using sort (Time ~ O(nlogn))

// approach#2 : using Heaps (Time ~ O(nlogK))

class Solution {
public:
    vector<int> nearlySorted(int a[], int n, int K) {
        // Your code here

        vector<int> arr ;
        for(int i =0 ; i < n ; i++) {arr.push_back(a[i]) ;}

        priority_queue<int, vector<int> , greater<int>> pq ;
        for(int i =0 ; i <= K ; i++) {pq.push(arr[i]) ;}

        int i = 0 ;
        while(!pq.empty()) {
            arr[i] = pq.top() ; pq.pop() ;
            if(i+1+ K < n) {
                pq.push(arr[i+1+K]) ;
            }
            i++ ;
        }

        return arr ;  

    }
};