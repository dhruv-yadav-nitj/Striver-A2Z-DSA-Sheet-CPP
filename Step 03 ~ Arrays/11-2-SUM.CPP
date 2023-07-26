#include <bits/stdc++.h>
using namespace std;

// approach #1 : using hashing
class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        // code here
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(x - arr[i]) != mp.end())
            {
                return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};

// approach #2 : using two pointer
class Solution {
public:
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
        // code here
        sort(arr, arr + n) ; int i =0 , j = n-1 ;
        while(i < j) {
            if(arr[i] + arr[j] == x) {return true ;}
            else if(arr[i] + arr[j] > x) {--j ;}
            else{
                ++i ;
            }
        }
        return false ;

    }
};