#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1

// this should be the solution if we are asked to print the subarray with max sum
class Solution {
public:
    vector<int> findSubarray(int a[], int n) {
        // code here
        int ansStart, start = 0, ansEnd ; int maxi = INT_MIN, sum = 0 ;
        for(int i =0 ;i < n ; i++) {
            if(sum ==0) {
                // starting of new subarray
                start = i ;
            }
            sum += a[i] ;
            if(maxi < sum) {
                maxi = sum ;
                ansStart = start ; ansEnd = i ;
            }
            if(sum < 0) {
                sum =0 ;
            }
        }
        vector<int> ans;
        for(int i =ansStart ; i <= ansEnd ; i++) {
            ans.push_back(a[i]) ;
        }
        return ans ;
        
    }
};

// but the gfg version of this problem had some variation than we cant include -ve elements in the ans subarray and if two subarray have same sum then consider the subarray having max Length -> this variation makes this problem HARD
class Solution {
public:
    vector<int> findSubarray(int a[], int n) {
        // code here
        int ansStart = -1, start = 0, ansEnd =-1 ; int maxi = INT_MIN, sum = 0 ;
        for(int i =0 ;i < n ; i++) {
            // according to the problem we have not to consider the -ve elements -> so this would mark the end of the exisiting subarray -> just mark sum =0
            if(a[i] < 0){
                sum = 0; continue;
            }
            if(sum ==0) {
                // starting of new subarray
                start = i ;
            }
            sum += a[i] ;
            if(maxi <= sum) {
                // if the new sum is greater than maxi -> just update the start and end of ans subarray
                if(maxi < sum) {
                    ansStart = start ; ansEnd = i ;
                }
                // else if the newSum is equal to existing maxi -> just check the length of new subarray and old ans subarray and update if the new subarray has length greater than existing ans subarray
                else{
                    if(ansEnd - ansStart < i - start) {
                        ansStart = start ; ansEnd = i ;
                    }
                }
                maxi= sum ;
            }
            // neglect the subarray giving negative sum
            if(sum < 0) {
                sum =0 ;
            }
        }
        vector<int> ans;
        for(int i =ansStart ; i <= ansEnd ; i++) {
            ans.push_back(a[i]) ;
        }
        return ans ;
        
    }
};