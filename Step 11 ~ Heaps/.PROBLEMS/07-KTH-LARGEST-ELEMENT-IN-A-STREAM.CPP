#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    // take a min-heap
    priority_queue <int, vector<int> , greater<int>> pq ; int k ; 
    KthLargest(int k, vector<int> &nums) {
        this-> k = k ;
        for(auto it : nums) {
            pq.push(it) ;
        }

        while(pq.size() > k) {
            pq.pop() ;
        }
        // now our heap is having kth largest element on its top
    }

    int add(int val) {
        pq.push(val) ;
        if(pq.size() > k) {pq.pop() ;}
        // only those numbers would play some role in kth largest that are greater than the current top of priority queue
        return pq.top() ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// GFG VERSION 
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq ;

        vector<int> ans ;
        

        // though this was not necessary but gfg was giving TLE if we did this problem in a single loop so instead we divided the problem into first k elements and then rest elements to save the insertion and deletion time in min-heap
        for(int i =0 ; i < k-1; i++) {
            ans.push_back(-1) ;
        }
        
        for(int i=0 ; i< k ; i++) {
            pq.push(arr[i]) ;
        }
        
        ans.push_back(pq.top()) ;

        for(int i =k ; i < n ; i++) {
            
            // pushing an element in the min-heap is meaning full only if the element is larger than the top element of min-heap
            if(pq.empty() or arr[i] > pq.top()) {
                pq.push(arr[i]) ;
            }
            if(pq.size() < k) {ans.push_back(-1) ; continue;}
            else{
                if(pq.size() > k) {pq.pop() ;}
                ans.push_back(pq.top()) ;
            }
        }
        return ans ;
        
    }
};