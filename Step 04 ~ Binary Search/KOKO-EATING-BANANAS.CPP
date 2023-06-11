#include <bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    static bool compare (int a, int b){
        return a < b ;
    }

    bool isValid (int mid , vector<int>piles, int h){

        int count = 0;
        for(int i=0 ; i < piles.size() ; i++){
            count += ceil(piles[i]/(float)mid) ;
        }

        return (count <= h) ;
    }

    int Solve(int N, vector<int>& piles, int H) {
        // Code here

        if(H < N){return -1 ;}

        int low = 0 , high = piles[distance(piles.begin() , max_element(piles.begin() , piles.end(), compare))], mid ;
        
        // this case was not required i guess.. but the ques had some edges case for H = 1, so I fixed that in this way
        if(H == 1){
            return high ;
        }

        int ans = -1 ;

        // our ans would be in the range of 0 and max bananas in a pile
        while(low <=high){
            mid= low + (high -low)/2 ;
            if(isValid(mid , piles, H)){
                ans = mid ; high = mid -1 ;
            }
            else{
                low = mid +1 ;
            }
        }

        return ans ;

    }
};