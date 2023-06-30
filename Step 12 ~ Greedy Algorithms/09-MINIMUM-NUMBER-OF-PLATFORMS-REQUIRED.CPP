#include <bits/stdc++.h>
using namespace std;

// Good Problem

// Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other.

// this problem is exact opposite of the previous problem
// this problem is differnt from other greedy algo problems done till now -> here we will see another way to approach greedy problems

// basically the intuition is that we need to count the number of overlapping trains -> max number of overlapping trains over a period of time would be the ans
// this can be achieved using a nested for loop (https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/) article approach

// Time ~ O(nlogn)
// Space ~ O(1)
class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        // Your code here

        multiset<pair<int, char>> st ; // multisets are used to store multiple iteration of a single element and all the items are stores in sorted order too
        for(int i =0 ; i < n ; i++) {
            st.insert({arr[i] , 'a'}) ;
            st.insert({dep[i] , 'd'}) ;
        }

        int curr(0) , maxi (0) ; // curr would store the number of trains overlapping at a time and maxi would store the max number of trains overlapping over the whole time

        // counting max number of overlapping trains
        for(auto it : st) {
            if(it.second == 'a') {
                curr++ ;
            }
            else{
                curr-- ;
            }
            maxi =max(maxi , curr);
        }

        return maxi ;
        
    }
};

// Approach #2 : Optimised Approach
// Time ~ O(nlogn) Space ~ O(1) 
// this approach is similar to the above approach just we are optimising the space required 
class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        // Your code here


        // At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

        sort(arr, arr + n) ; sort(dep , dep +n);

        int i =1 , j =0 , count =1 , maxi =1 ;
        while(i < n and j < n ) {
            if(arr[i] <= dep[j]) {
                count++ ; i++ ;
            }
            else{
                count-- ; j++ ;
            }
            maxi = max(maxi ,count) ;
        }

        return maxi ;
        
    }
};