#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> ans ;
        for(int i=0; i< queries ; i++) {
            int ind = indices[i] ; int cnt(0) ;
            for(int j=ind+1; j < n ; j++) {
                if(arr[j] > arr[ind]) {
                    cnt++ ;
                }
            }
            ans.push_back(cnt) ;
        }
        return ans ;
    }
};