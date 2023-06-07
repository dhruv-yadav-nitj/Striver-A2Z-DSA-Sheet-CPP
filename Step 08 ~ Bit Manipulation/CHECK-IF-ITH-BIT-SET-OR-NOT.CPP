#include <bits/stdc++.h>
using namespace std ;

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        
        vector<int> binary ;
        while(n > 0){
            binary.push_back(n%2) ; n= n/2 ;
        }
        return (binary[k]==1) ;
        
        
    }
};