#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE -> take three nested loops and try out all possible triplets and store the ones giving zero on summation and are unique (which can be fixed by sorting the index of triplets giving zero and then storing them in a set)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // code here

        vector<vector<int>> ans ; int n = nums.size() ;
        set <vector<int>> st ;
        for(int i =0 ; i < n ; i++) {
            for(int j = i+1; j < n ; j ++) {
                for(int k = j +1 ; k < n ; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> vec = {i , j , k} ; sort(vec.begin() , vec.end()) ;
                        if(!st.count(vec)){st.insert(vec) ; ans.push_back(vec) ;}
                    }
                }
            }
        }
        return ans ;
    }
};

// OPTIMISED APPROACH
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // code here
        int n = nums.size() ; set<vector<int>> st ;
        for(int i =0 ;i < n; i++) {
            unordered_set<int> pk ;
            for(int j =i+1; j < n ; j++) {
                int req = -(nums[i] + nums[j]) ;
                if(pk.count(req)) {
                    vector<int> temp = {nums[i], nums[j], req} ; sort(temp.begin() , temp.end()) ;
                    st.insert(temp) ;
                }
                pk.insert(nums[j]) ;
            }
        }

        vector<vector<int>> ans (st.begin() , st.end()) ;
        return ans ;
    }
};

// MOST EFFICIENT APPROACH
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // code here
        int n = nums.size() ; vector<vector<int>> ans ;

        sort(nums.begin() , nums.end()) ;

        for(int i =0 ; i < n -2; i ++) {
            
            // skip all those elements which are equal to its previous ones
            if(i ==0 or (i > 0 and nums[i-1] != nums[i])) {
                int low = i +1 , high = n-1 , req = -(nums[i]) ;
                while(low < high) {

                    if(nums[low] + nums[high] == req) {
                        ans.push_back({nums[i], nums[low] , nums[high]}) ;

                        while (low < high and nums[low] == nums[low+1]){low++ ;}
                        while (low < high and nums[high] == nums[high-1]){high-- ;}

                        low++, high-- ;

                    }
                    else if(nums[low] + nums[high] < req) {low++ ;}
                    else{high-- ;}
                }
            }
        }

        return ans ;

    }
};