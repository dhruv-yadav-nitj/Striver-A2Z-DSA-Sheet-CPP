#include <bits/stdc++.h>
using namespace std ;

// again applied the pick and not pick technique tought by striver and just modified this technique accordingly for the problem

class Solution
{
    public:
    void recursion (string s ,int k , int balance, vector<string>&ans){
        // recursion function base case
        if(k==0){
            int remove = balance ;
            while(balance > 0){
                s += ")" ; balance-- ;
            }
            ans.push_back(s) ;
            while(remove> 0){
                s.pop_back() ; remove-- ;
            }
            return ;
        }

        s += "(" ;
        recursion(s , k -1 , balance +1 , ans) ;

        s.pop_back() ;

        if(balance >0){
            s += ")" ;
            recursion(s, k , balance -1 , ans) ;
        }
    }
    
    vector<string> AllParenthesis(int n){
        // Your code goes here 
        vector<string> ans ;
        recursion("", n, 0, ans) ; return ans ;
        
    }
};