#include <bits/stdc++.h>
using namespace std;

// approach #1 : brute force : copy all the elements of the matrix into some vector and sort the vector then return the middle most element
// Time ~ O(RxC) + O((logRxC)xRxC) and Space ~ O(RxC)

// approach #2 : using binary search
int median(vector<vector<int>> &matrix, int R, int C){
    // code here

    // we would be using binary search in range

    int low=INT_MAX, high = INT_MIN, mid ;
    for(int i= 0; i < R ; i++){
        low = min(low, matrix[i][0]) ;
        high = max(high, matrix[i][C-1]) ;
    }

    while(low <= high){
        mid = low + (high -low)/2 ;
        int count=0 ;
        for(int i =0;i < R ; i++){
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
        }

        if(count <= (R*C)/2){
            low=mid+1 ;
        }
        else{
            high = mid -1;
        }
    }

    return low;
}