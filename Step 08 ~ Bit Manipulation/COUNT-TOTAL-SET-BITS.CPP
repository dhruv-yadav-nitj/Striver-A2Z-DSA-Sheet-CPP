#include <bits/stdc++.h>
using namespace std ;

// brute force
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n){
        // Your logic here

        int ans = 0 ;
        for(int k =1 ; k <= n ; k++){
            
            // counting number of set bits in each number seperately
            int count=0 , i = k ;
            while(i > 0){
                count += (i%2) ;
                i = i /2 ;
            }
            ans += count ;

        }

        return ans ;

    }
};

// using bit operation
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n){
        // Your logic here

        int count =0 ;
        for(int i =1; i <= n ; i++){
            int k = i ;
            while(k > 0){
                count += (k&1) ;
                k = (k >> 1) ; // right shift by 1 means divide by 2
            }
        }
        return count ;
    }
};

// using STL
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n){
        // Your logic here
        int ans =0 ;
        for(int i =1 ; i <= n ; i++){
            ans += __builtin_popcount(i) ;
        }

        return ans ;
        
    }
};

// optimised approach
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int solve (int n){
        if(n<= 1){
            return n ;
        }
        int k = floor(log2(n)) ;
        return k*pow(2, k-1) + (n - pow(2, k) + 1) + solve(n - pow(2, k)) ;
    }
    int countSetBits(int n){
        return solve(n) ;
    }
};
// Optimised Approach is tricky --> read the article : https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/