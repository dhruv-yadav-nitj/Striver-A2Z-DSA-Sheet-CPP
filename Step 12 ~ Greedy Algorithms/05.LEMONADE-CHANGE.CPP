#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int count5 =0 , count10 =0 ;
        for(auto it : bills) {
            if(it == 5) {
                ++count5 ;
            }
            else{
                if(it ==10) {
                    if(count5 > 0) {
                        count10++ , count5-- ;
                    }
                    else{
                        return false ;
                    }
                }
                else{
                    // means the customer gave us 20 rupee bill
                    // case 1 : if we have both 10 and 5 available
                    if(count10 >0 and count5 > 0){
                        count10-- , count5-- ; continue;
                    }
                    
                    // case 2 : if we only have 5 availables
                    if(count5 >= 3) {
                        count5 = count5 -3 ;
                    }
                    // else -> in any other case the exchange is not possible
                    else{
                        return false ;
                    }
                }
            }
        }
        return true ;
    }
};