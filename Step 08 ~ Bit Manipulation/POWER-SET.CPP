#include <bits/stdc++.h>
using namespace std ;

// did not used any concept of bit manipulation but used basic recursion technique of pick and not pick

class Solution{
	public:
        void solve (string s , int ind , string temp , vector<string>&ans){
            // base condition
            if(ind == s.length()){
                ans.push_back(temp); 
                return ;
            }

            // pick
            temp += s[ind] ;
            solve(s ,ind +1 , temp,  ans) ;

            // not pick
            temp.pop_back() ;
            solve(s, ind+1, temp , ans) ;

        }
		vector<string> AllPossibleStrings(string s){
		    // Code here
            vector<string> ans; 
            solve(s, 0, "" , ans) ;
            ans.pop_back() ; sort(ans.begin(), ans.end()) ;
            return ans ;

		}
};