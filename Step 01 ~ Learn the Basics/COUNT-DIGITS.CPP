#include <bits/stdc++.h>
using namespace std ;

// https://practice.geeksforgeeks.org/problems/count-digits5716/1

class Solution{
public:
    int evenlyDivides(int N){
        //code here

        string temp = "" ; temp = to_string(N) ; int count=0; 
        for(auto x : temp){
            int curr = x - '0' ; if(curr != 0 and N%curr == 0){count++ ;}

        }

        return count ;
        
    }
};