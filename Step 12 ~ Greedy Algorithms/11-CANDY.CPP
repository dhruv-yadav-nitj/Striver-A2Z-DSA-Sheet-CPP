#include <bits/stdc++.h>
using namespace std;

// Intuition is SIMPLE and TRICKY at the same time

class Solution {
public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        vector<int> candy (N , 1) ; // first given all the children 1 candy

        // compare with left neighbour
        for(int i =1 ; i < N ; i++) {
            if(ratings[i] > ratings[i-1]) {
                // if a child has rating greater than its left neighbour -> then this child should get +1 candy than its left neighbour
                candy[i] = candy[i-1] +1 ;
            }
        }

        // compare with right neighbour
        for(int i = N-2 ; i >= 0 ; i--) {
            if(ratings[i] > ratings[i+1]) {
                // if a child has rating greater than its right neighbour -> he should get +1 candy greater than its right neighbour but at the same time we should not forget the setting we have done according to left neighbours -> so we would take max

                // for example -> take {11, 12, 13, 10} -> first candies = {1, 1, 1, 1} -> after comparing the left neighbours, candies = {1, 2, 3, 1} -> after comparing right neighbours, candies = {1, 2, max(3, 2), 1} -> so see at the child with rating 13 -> that's the edge case we are handling with taking max of both sides

                candy[i] = max(candy[i] , candy[i+1] +1) ;
            }
        }

        return accumulate(candy.begin() , candy.end() , 0) ;
    }
};