#include <bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    //You need to complete this fucntion

    long long recursion (int base , int exp){

        if(exp ==0){return 1 ;}

        long long result = recursion (base , exp /2) ;
        result = (result * result)%((int)(1e9 + 7)) ;

        if(exp %2==1){
            result= (result * base) % ((int)(1e9 + 7)) ;
        }
        return result ;
    }
    
    long long power(int N,int R){
       //Your code here
       return recursion(N, R) ;
    }

};