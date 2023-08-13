#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        // code here

        /*
        approach
        -> store the freq of each chars in a hashmap
        -> make a vector of pair<int, char> and copy all the values of the map into it and sort it
        -> make a new string based on the freq stores in this vector
        */

       unordered_map<char,int> mp ;
       for(auto it : s) {
            mp[it]++ ;
       }

       vector<pair<int,char>> vc ;
       for(auto it : mp) {
            char temp = it.first ; int freq=  it.second ;
            vc.push_back({freq, temp}) ;
       }
       sort(vc.begin() , vc.end(), greater()) ; // sort the vector in non-increasing order
       string ans = "" ;
       for(auto it: vc) {
            int c = it.second , f =it.first ;
            for(int i =1 ; i <= f ; i++) {
                ans += c ;
            }
       }
       return ans ;

    }
};