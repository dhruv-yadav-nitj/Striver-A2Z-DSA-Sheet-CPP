#include <bits/stdc++.h>
using namespace std ;

// just apply the pick and not pick technique

class Solution{
	public:
        void recursion (string temp, string s , int index , vector<string>&ans){
            
            // base condition
            if(index == s.length()) {
                if(temp == ""){
                    return ;
                    // since according to the problem we dont need to print the empty set
                }
                ans.push_back(temp) ; return ;
            }

            // pick
            temp += s[index] ;
            recursion(temp , s , index +1 , ans) ;

            // not pick
            temp.pop_back() ;
            recursion(temp , s,  index +1 , ans) ;

        }
		vector<string> AllPossibleStrings(string s){
		    // Code here
            vector<string> ans ;
            recursion("", s, 0 , ans) ; sort(ans.begin(), ans.end()) ; return ans;
		}
};