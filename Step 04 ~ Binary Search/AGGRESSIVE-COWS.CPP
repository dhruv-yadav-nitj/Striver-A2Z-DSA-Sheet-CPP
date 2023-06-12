#include <bits/stdc++.h>
using namespace std ;

// Approach is simple : apply binary search in space range

class Solution {
public:

    bool isValid (vector<int>s , int k, int mid){
        int count =1 , prev=s[0] ; // initially place the first cow at stall no. 1 which is at index 0 of stalls and take the count of cows placed as 1
        for(int i=1; i< s.size() ; i++){
            if(abs(s[i] - prev) >= mid){
                count++ ; prev = s[i] ;
                if(count == k){return true ;}
            }
        }
        return false ;
    }
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin() , stalls.end()) ;
        int low =0, high = stalls[distance(stalls.begin() , max_element(stalls.begin() , stalls.end()))], mid , ans ;
        while(low <= high){
            mid = low +(high -low)/2 ;
            if(isValid(stalls, k, mid)) {
                ans = mid , low = mid+1 ;
            }
            else{
                high = mid-1 ;
            }
        }
        return ans ;
    }
};