#include <bits/stdc++.h>
using namespace std;

// case 1: if the array has only positive elements
// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?leftPanelTab=0

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int ans =0 , i =0 , j=0, n = a.size() ;
    long long sum = 0 ;
    while(j < n) {
        if(sum + a[j] <= k) {
            sum = sum + a[j] ;
            if(sum == k) {
                ans = max(ans, j -i +1 );
            }
            ++j ;
        }
        else{
            sum = sum - a[i] ;
            ++i ;
        }
    }
    return ans ;
}

// case 2 : if the array has both +ve and -ve elements
// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// approach #1 : checking every possible subarray
class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        // Complete the function
        int ans =0 ;
        for(int i =0 ; i < N ; i++) {
            int sum = 0 ;
            for(int j = i ; j < N ; j++) {
                sum += A[j] ;
                if(sum == K) {ans = max(ans, j -i +1) ;}
            }
        }
        return ans ;

    }
};
// approach #2 : optimised approach
class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        // Complete the function
        
        unordered_map<int,int> mp ;
        int ans = 0 , sum =0 ;
        for(int i =0 ; i < N ; i++) {
            sum += A[i] ;
            if(sum == K) {
                ans = max(ans , i +1 );
            }
            
            if(mp.find(sum - K) != mp.end()) {
                ans = max(ans , i - mp[sum - K]) ;
            }
            // if some item has not occured before -> then update only
            if(mp.find(sum) == mp.end()) {
                mp[sum]= i ;
            }
        }
        return ans ;

    }
};

// also see the problem #23