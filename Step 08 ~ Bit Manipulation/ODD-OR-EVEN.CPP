#include <bits/stdc++.h>
using namespace std ;

class Solution{   
public:
    string oddEven(int N){
        // code here 
        
        if(N&1==1){
            return "odd" ;
        }
        else{
            return "even" ;
        }
        
    }
};