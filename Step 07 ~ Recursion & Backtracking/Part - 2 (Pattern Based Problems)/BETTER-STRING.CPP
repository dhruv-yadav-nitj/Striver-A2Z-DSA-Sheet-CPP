#include <bits/stdc++.h>
using namespace std ;

// approach #1 : using recursion
// applied pick and not pick but giving TLE
class Solution {
  public:
    void recursion (string temp, string s , int index , unordered_set<string>st){
        
        // base condition
        if(index == s.length()) {
            if(temp == ""){
                return ;
                // since according to the problem we dont need to print the empty set
            }
            st.insert(temp) ; return ;
        }
        // pick
        temp += s[index] ;
        recursion(temp , s , index +1 , st) ;
        // not pick
        temp.pop_back() ;
        recursion(temp , s,  index +1 , st) ;
    }
    string betterString(string str1, string str2) {
        // code here
        int count1 = 0 , count2 =0 ;
        unordered_set <string> st1 , st2 ;
        recursion("" , str1 , 0 , st1) ; recursion("" , str2 , 0 , st2) ; 
        count1 = st1.size() , count2 = st2.size() ;
        if(count1 >= count2){return str1 ;}
        else{
            return str2 ;
        }

    }
};

// approach #2 : using DP