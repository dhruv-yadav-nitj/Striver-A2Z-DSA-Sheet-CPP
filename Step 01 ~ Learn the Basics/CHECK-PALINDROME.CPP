#include <bits/stdc++.h>
using namespace std ;

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    string temp = to_string(n) ;
            for(int i =0; i < temp.length() ; i++){

                if(temp[i] != temp[temp.length() - 1 -i]){
                    return "No" ;
                }
            }

            return "Yes" ;
		    
		}
};