#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    bool isValid (vector<int> s , int mid , int m, int k){
        int count= 0, flower = 0 ;
        for(int i =0 ; i < s.size() ; i++){
            if(s[i] <= mid){
                flower++ ;
                if(flower == k){
                    count++ ;
                    flower = 0 ;
                }
            }
            else{
                flower = 0 ;
            }
        }
        return (count >= m) ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = 0 , high = bloomDay[distance(bloomDay.begin() , max_element(bloomDay.begin() , bloomDay.end()))] ;
        // low is the min day to make m bouqets and high is the max day we can take to make m bouqets (initially assume that we can make m bouqets in 0 days (which is min) and obviusly we would take max days by taking that flower which takes max time to grow so high = max_element)
        int mid , ans = -1 ;

        while(low <= high){
            mid = low + (high -low)/2 ;
            // we would check if we can make m bouqets in mid no. of days or not --> if yes then we would again check by decreasing the range
            if(isValid (bloomDay , mid , m , k)){
                ans = mid ; high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans ;
        
    }
};