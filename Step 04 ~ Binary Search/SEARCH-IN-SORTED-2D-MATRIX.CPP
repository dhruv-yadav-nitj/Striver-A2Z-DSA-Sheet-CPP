#include <bits/stdc++.h>
using namespace std;

// Type : 1 [Monotonically Increasing Matrix]
// for a matrix that is sorted row wise and col wise i.e., the elements of the matrix are monotonically increasing so we can apply binary search in the 2d matrix assuming it as a 1d array
// https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
int matSearch(vector<vector<int>> &mat, int N, int M, int X){
    // your code here
    int n = N , m = M , low = 0 , high = n*m -1 , mid;
    while(low <= high){
        mid = low+ (high -low)/2 ;
        int i = mid/m , j = mid%m ;
        if(mat[i][j]== X){return 1 ;}
        else if(mat[i][j] > X){
            high = mid -1 ;
        }
        else{
            low = mid+1 ;
        }
    }

    return 0 ;
}

// Type : 2 [Row wise Col wise Sorted Only]
// https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
// but in the given problem, each row and each col is sorted but the elements are not monotonically increasing, so we need to follow some other approach
// [approach]
// we would use elimination of row and col method --> lets start from top right corner of the matrix i = 0 and j = m -1 --> if the target == mat[i][j] then found else --> if the curr element < target --> then we can say that all the elements in the curr row are smaller than target (bcz row wise sorted) so i++ and else it can happen that curr element is greater than target --> means all the remaining elements in this col would be greater than the target --> so we can do j--
int matSearch (vector <vector <int>> &mat, int N, int M, int X){
    // your code here

    int i = 0 , j = M-1 , target = X;
    while(i < N and j >= 0)    {
        if(mat[i][j]==target){return 1 ;}
        else if(mat[i][j] < target){
            i++ ;
        }
        else{
            // mat[i][j] > target --> eliminate this col
            j-- ;
        }
    }

    return 0 ;
    
}