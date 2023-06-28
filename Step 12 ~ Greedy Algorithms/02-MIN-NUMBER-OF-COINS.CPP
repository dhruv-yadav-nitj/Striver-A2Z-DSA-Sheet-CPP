#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N){
        // code here

        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1} ; vector<int> ans ;
        int i =0 ;
        while(N > 0 and i < coins.size()) {
            if(N >= coins[i]) {
                ans.push_back(coins[i]) ; N = N - coins[i] ;
            }
            else{
                i++ ;
            }
        }

        return ans ;

    }
};