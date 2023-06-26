#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz){
        // code here
        sort(greed.begin() ,greed.end()) ; sort(sz.begin() , sz.end()) ;

        int i = 0 , j = 0 ; int count(0) ;
        while(i < N and j < M) {
            if(sz[j] >= greed[i]) {
                count++ ; i++ , j++ ;
            }
            else{
                j++;
            }
        }

        return count ;
    }
};