#include <bits/stdc++.h>
using namespace std ;

// Sieve of Eratosthenes
// Time ~ O(N * log(logN))

class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N){
        // Write Your Code here

        vector<bool> isPrime (N+1 , true) ;
        isPrime[0] = isPrime[1] =  false ;

        for(int i=2 ; i*i <= N ; i++){

            if(isPrime[i]){

                for(int k = i*i ; k <= N ; k += i){
                    isPrime[k]= false ;
                }
            }
        }

        vector<int> ans ;
        for(int i = 2 ;i <= N; i++){

            if(isPrime[i]){
                ans.push_back(i) ;
            }
        }

        return ans ;
    }
};