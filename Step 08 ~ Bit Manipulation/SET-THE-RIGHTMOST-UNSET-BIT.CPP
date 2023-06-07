#include <bits/stdc++.h>
using namespace std ;

class Solution
{
public:
    int setBit(int N){
        // Write Your Code here

        if(N%2==0){
            // if the N is even then we can simply return the next natural number --> bcz in an even number the right most unset bit would be the LSB --> when LSB is set then only 1 is added in existing number
            return N+1 ;
        }
        else{

            bool flag= false ;
            vector<int> binary ;
            while(N > 0){
                if(!flag and N%2==0){
                    binary.push_back(1) ; flag= true ;
                }
                else{
                    binary.push_back(N%2) ;
                }
                N /= 2 ;
            }

            int ans = 0 ;
            for(int i =0 ;i < binary.size() ; i++){

                ans += (binary[i] * pow(2, i)) ;
            }

            return ans ;
        }

    }
};