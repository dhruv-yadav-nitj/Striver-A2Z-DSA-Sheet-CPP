#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557

bool isValid (vector<int>&arr, int n, int k, int mid) {
    // check if its is possible to paint all the boards in mid unit of time
    int cnt = 1 , temp =0 ;
    for(int i =0 ; i < n ; i++) {
        if(temp + arr[i] <= mid) {
            temp += arr[i] ;
        }
        else{
            if(arr[i] > mid) {
                return false ;
            }
            temp = arr[i] , cnt++ ;
            // assign this board to the next painter
            if(cnt > k) {return false ;}
        }
    }
    return (cnt <= k) ;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size() ;
    int low = *max_element(boards.begin(), boards.end()) , high = accumulate(boards.begin(), boards.end() , 0) , mid ;
        int ans = 0 ;
        while(low <=  high) {
            // cout << mid << " " ;
            mid = low + (high -low)/2 ;
            if(isValid(boards, n , k , mid)) {
                ans = mid ;
                high = mid -1 ;
            }
            else{
                low = mid +1 ;
            }
        }
        return ans ;
}