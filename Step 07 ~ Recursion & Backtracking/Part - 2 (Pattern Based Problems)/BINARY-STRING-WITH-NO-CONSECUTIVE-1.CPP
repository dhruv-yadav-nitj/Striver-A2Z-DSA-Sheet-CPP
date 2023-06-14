#include <bits/stdc++.h>
using namespace std ;

// https://www.codingninjas.com/codestudio/problems/binary-strings-with-no-consecutive-1s_893001?leftPanelTab=0

// just follow the pick and not pick techniques (just replace pick with picking 0 and not picking with picking 1)

void recursion (string s , int index ,int k, vector<string>&ans){
    if(index==k){
        ans.push_back(s) ; return ;
    }
    
    // pick 0 and then again apply recursion
    s += "0" ;
    recursion(s , index +1 , k, ans) ;

    // pop the last added 0 in the string
    s.pop_back() ;

    // if the last added character was not 1 then only pick 1 (bcz we dont want two consecutive 1's)
    if(s.back() != '1'){
        s += '1' ; recursion(s, index +1, k, ans) ;
    }
}

vector<string> generateString(int k) {
    // Write your code here.
    vector<string> ans ;
    recursion("" , 0 , k, ans) ; return ans ;

}
