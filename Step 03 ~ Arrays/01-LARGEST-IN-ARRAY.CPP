#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        return *max_element(arr.begin() , arr.end()) ;
    }
};