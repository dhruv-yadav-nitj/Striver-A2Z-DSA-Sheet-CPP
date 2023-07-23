#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here

        unordered_map<int,int> mp ; vector<int> ans ;
        for(auto it : arr) {
            mp[it]++ ;if(mp[it] > 1) {ans.push_back(it) ;}
        }
        for(int i= 1; i<= n ; i++) {
            if(mp[i] ==0) {
                ans.push_back(i) ;
            }
        }
        return ans ;

    }
};