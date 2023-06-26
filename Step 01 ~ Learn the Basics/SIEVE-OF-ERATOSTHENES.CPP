#include <bits/stdc++.h>
using namespace std ;

// sieve of eratosthenes --> most efficient method to find all the prime numbers less than the number n, where n is less than 10 million
// Time Complexity : O(N * log(logN))

void sieve(int n){

    bool prime[100000] ; memset(prime, true , sizeof(prime)) ;

    for(int i =2 ; i*i <= n ; i++){

        if(prime[i]){

            for(int p = i*i ; p <= n ; p+=i){
                prime[p] = false ;
            }
        }
    }

    for(int i =2 ; i <= n ; i++){
        if(prime[i]){cout << i << " " ;}
    }cout << endl ;
}

int main(int argc, char const *argv[])
{
    int n ; cin >> n ;
    sieve(n) ;
    return 0;
}