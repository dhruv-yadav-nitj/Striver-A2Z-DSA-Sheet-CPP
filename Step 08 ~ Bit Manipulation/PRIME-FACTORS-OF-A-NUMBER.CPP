#include <bits/stdc++.h>
using namespace std ;

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here

        vector<int> ans ;
        for(int i =2 ; i <= N ; i++){

            if(N%i ==0){
                ans.push_back(i) ;
                while(N%i==0){
                    N /= i ;
                }
            }
        }
        return ans ;

	}
};