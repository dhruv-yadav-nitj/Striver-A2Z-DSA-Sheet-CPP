#include <bits/stdc++.h>
using namespace std;

// [EASY]

class Solution {
public:
    long long minCost(long long arr[], long long n) {
        // Your code here

        priority_queue<long long, vector<long long> , greater<long long>> pq ;
        for(int i =0; i < n ; i++) {
            pq.push(arr[i]) ;
        }   
        long long ans = 0 ;
        while(pq.size() > 1) {

            long long a=0, b=0 ;
            a = pq.top() ; pq.pop() ; b = pq.top() ; pq.pop();

            ans = ans + (a + b) ;
            pq.push(a+ b) ;
        }

        return ans ;

    }
};