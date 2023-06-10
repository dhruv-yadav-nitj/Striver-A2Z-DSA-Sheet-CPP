#include <bits/stdc++.h>
using namespace std;

// approach #1 : using normal linear search
// intuition --> since the elements in each row are sorted --> the row in which the first 1 appears most earlier (i.e. the first occurence of 1 in a row) would contain the most number of 1s
int rowWithMax1s(vector<vector<int>> arr, int n, int m){
    // code here
    
    for(int col = 0 ; col < m ; col++){
        for(int row = 0 ; row < n ; row++){
            if(arr[row][col]==1){
                return row ;
            }
        }
    }

    return -1;
}

// approach #2 : using binary search algo
// Time ~ O(n*logm)
int rowWithMax1s(vector<vector<int>> arr, int n, int m){
    // code here
    int max_ones = 0 , ans =-1 ;
    for(int i =0 ;i < n ; i++){

        int low = 0 , high = m-1 , mid ;
        while(low <= high){
            mid = low + (high -low)/2 ;
            if(arr[i][mid] == 1){
                high = mid -1 ;
            }
            else{
                low = mid +1 ;
            }
        }

        if(max_ones < m - low){
            max_ones = m -low ; ans = i ;
        }

    }

    return ans ;

}