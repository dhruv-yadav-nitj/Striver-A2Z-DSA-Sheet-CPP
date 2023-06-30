#include <bits/stdc++.h>
using namespace std;

// Greedy Approach -> Intuition -> 

class Solution {
public:
    int canReach(int A[], int N) {
        // code here

        // start from the very end (kinda top-down approach in DP)
        bool flag= true ; int i =N -1, j ; // take a bool -> which tells us whether its possible to reach end or not

        // since we have to reach the last index -> so we have nothing to do with the element which is at last index it can be either zero or anything -> bs uske phle k jitne elements hain agar wo hme last index tk pahucha skta hain then its good and thats all we want -> so start with second last index
        for(int i =  N-2 ; i >= 0 ; i--) {
            if(A[i] ==0 and flag) { // if we encounter the first zero from last -> store the index -> so now we have to search for an element which helps us over come this 0 wla index -> so agar us non zero element aur is current index k beech koi zero aaega to hm use ignore krenge bcz usko consider krke bhi koi faayda nhi hain -> this can be ignore using a extra boolean check
                j = i ; flag= false ; continue;
            }
            // if we encounter any non zero number which is enough large so that it can jump the index where we encountered our last zero -> then again set flag= true 
            if(!flag and A[i] > 0) {
                if(A[i] > j -i) {
                    flag= true ;
                }
            }
        }
        return flag;

    }
};