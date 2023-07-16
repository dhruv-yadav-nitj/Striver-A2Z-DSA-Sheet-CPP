#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int act = accumulate(array.begin() , array.end() , 0) , tot = (n * (n+1))/2 ;
        return tot - act ;
    }
};