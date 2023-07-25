#include <bits/stdc++.h>
using namespace std;

/* 
Approach : 
-> first do the previous Majority Element Problem in which we had to return the element which occure more than n/2 times
-> once u have understanding of Moore's Voting Algorithm
-> this ques has asked to return all those elements which occur more than n/3 times -> so first lets see how many elements can occur more than n/3 times -> the ans is simple -> there can be min of 0 such elements and max of 2 such element which occur more than n/3 times (simple maths)
-> so instead of applying moore's voting algo on single element (as done in prev problem) apply this algo on two seperate elements
*/

// [BRUTE FORCE] -> for each element check if it occurs more than n/3 times using nested-loops -> Time ~ O(n^2)

// [SIMPLE] -> TIME ~ O(n) and Space ~ O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size() ; vector<int> ans ;
        unordered_map<int,int> mp ;
        for(auto it : nums) {
            if(mp[it] > n/3) {
                continue;
            }

            mp[it]++ ; if(mp[it] > n/3) {ans.push_back(it) ;}
        }
        return ans ;
    }
};

// [OPTIMISED APPROACH] -> using Moore's Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {

        int cnt1 =0 , cnt2= 0 , num1 = -1, num2 = -1 ;
        int n = nums.size() ;
        for(auto it: nums) {

            if(it == num1) {cnt1++ ;}
            else if(it == num2) {cnt2++ ;}

            else if (cnt1 ==0){num1 = it ; cnt1++ ;}
            else if (cnt2 ==0){num2 = it ; cnt2++ ;}

            else{cnt1--, cnt2--;}
        }

        cnt1 = 0, cnt2=0 ;
        // its not necessary that the above algo gives correct results -> so check it once
        for(auto it : nums) {
            if(it == num1){cnt1++ ;}
            else if(it == num2) {cnt2++ ;}
        }

        if(cnt1 > n/3 and cnt2 > n/3) {return {num1, num2} ;}
        else if (cnt1 > n/3) {return {num1} ;} else if(cnt2 > n/3) {return {num2} ;}
        else{return {-1} ;}

    }
};