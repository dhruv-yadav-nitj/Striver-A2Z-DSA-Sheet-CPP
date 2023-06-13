#include <bits/stdc++.h>
using namespace std ;

// https://practice.geeksforgeeks.org/problems/implement-atoi/1

// iterative approach
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int number= 0 , n = str.length() , j = 0 ;
        for(int i = n-1 ; i >= 0 ; i--, j++){
            if(i==0 and str[i] == '-'){
                continue ;
            }
            if(str[i] >= '0' and str[i] <= '9'){
                number = (pow(10, j) * (str[i] - '0')) + number ;
            }
            else{
                return -1 ;
            }
        }
        if(str[0]=='-'){
            return -number ;
        }
        return number ;
    }
};

// recursive approach
class Solution{
  public:

    int recursion(string str , int index, int result){
        if(index == str.length()){
            return result ;
        }

        int digit = str[index] - '0' ;

        if(digit >= 0 and digit <= 9){
            return recursion(str , index+1 , (result*10) + digit) ;
        }

        return result ;
    }
    
    int atoi(string str) {
        //Your code here
        return recursion(str, 0, 0) ;
    }
};