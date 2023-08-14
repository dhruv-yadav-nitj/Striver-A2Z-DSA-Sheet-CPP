#include <bits/stdc++.h>
using namespace std;
// Explanation : https://www.youtube.com/watch?v=lrSXKLmnMV8
// if u understand it once carefully -> its very easy problem

// [HARD]
// K stacks in an array of size N
class NStack {
    int *arr, *top, *next ; int free; int n, k; 
public:
    NStack(int N, int S) {
        // form N stacks in an array of size S
        this -> n = S; this -> k = N ;
        arr = new int[n]; top = new int[k]; next = new int[n] ;
        free =0 ; // first free space would be obviously 0th index
        // arr is the array that would store all the elements -> size = n
        // top is the array that would tell us the index where the top of kth stack is stored in the arr -> size = k
        // next is the array that can be used for two purposes -> it can tell us where is the next free space in the arr (when empty) and can also tell us the index of prev top (when filled)
        for(int i =0 ; i < k ; i++) {
            top[i] = -1 ;
        }
        for(int i =0; i <n; i++) {
            next[i] = i+1 ;
        }
        next[n-1] = -1 ;
    }
    bool push(int x, int m) {
        // push data = x into mth stack
        int i = free ; if(i == -1){return false ;}
        else{

            free = next[i] ;
            // since m is 1-indexed
            m = m-1 ;
            next[i] = top[m] ; // backtrack ka jugaad
            top[m] = i ; arr[i] = x ;
            // update the top and push the data into arr  
            return true ;          
        }
        
    }
    int pop(int m) {
        m -=1 ; // due to 1-based indexing

        if(top[m] == -1){return -1 ;}

        int i = top[m] ; int tomper = arr[i] ;
        top[m] = next[i] ;
        next[i] = free ; free = i ;
        return tomper ;
    }
};