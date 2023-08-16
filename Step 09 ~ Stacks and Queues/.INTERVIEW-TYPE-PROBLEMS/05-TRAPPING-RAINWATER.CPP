#include <bits/stdc++.h>
using namespace std;

// VERY VERY IMP PROBLEM -> IT WAS ASKED IN MICROSOFT INTERVIEW THIS YEAR, ALL THE POSSIBLE APPROACHES WERE ASKED (2023) (ON-CAMPUS)

// BRUTE FORCE --> Time ~ O(n^2)
/* If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index. Also we should observe that the boundary elevations would never be storing any water, so we can exclude the boundary heights during calculation. */
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size() , water=0;
        for(int i=1 ; i < n-1; i++) {
            int leftMax=height[i];int rightMax=height[i] ;
            int j=i-1, k=i+1 ;
            while(j >=0) {
                leftMax=max(leftMax,height[j--]) ;
            }
            while(k < n){
                rightMax=max(rightMax, height[k++]);
            }
            water += min(leftMax, rightMax)-height[i] ;
        }
        return water ;
    }
};

// OPTIMISED APPROACH --> Time ~ O(3n)
/* We can calculate and store leftMax and RightMax into some array before hand and then calculate the amount of water each index would store after doing one more traversal. */
class Solution {
public:
    int trap(vector<int> &height) {
        int n =height.size(); vector<int> leftMax (n) , rightMax(n) ;
        int lTemp =INT_MIN, rTemp = INT_MIN ;
        for(int i =0; i < n; i++) {
            leftMax[i]= lTemp = max(lTemp, height[i]) ;
        }
        for(int i=n-1; i>=0;i--){
            rightMax[i]=rTemp = max(rTemp, height[i]);
        }
        int water(0) ;
        for(int i=0 ; i < n; i++) {
            water += min(leftMax[i], rightMax[i])-height[i] ;
        }
        return water ;
    }
};

// USING STACK --> Time ~ O(N) and Space ~ O(N)
/* We'll keep inserting the block's index to stack until we found
currently iterated element is greater than element at top of stack
once we found that case we'll calculate the sum of the water
accumulated by each of the block
Note that when we encounter the higher block we actually
calculate the water accumulated by block at top of stack
and repeatedly do this task for all blocks inside our stack's top */
class Solution {
public:
    int trap(vector<int> &height) {
        
        stack<int> st ; int water (0) ;
        for(int i =0; i < height.size() ; i++) {

            while(!st.empty() and height[i]>height[st.top()]){

                int temp = st.top(); ; st.pop() ;

                if(st.empty()) {break ;}

                int w = i - st.top() -1 ; // width
                int h = min(height[st.top()], height[i]) - height[temp] ; // height

                water += (w*h) ;
            }
            st.push(i) ;
        }
        return water ;
    }
};

// MOST OPTIMISED
// Two Pointers Approach
class Solution {
public:
    int trap(vector<int> &height) {
        
        int n = height.size() ;
        int left= 0, right = n-1, water=0, maxLeft=0, maxRight=0;
        while(left <= right) {

            if(height[left]<=height[right]) {
                if(height[left] >= maxLeft) {
                    maxLeft=height[left] ;
                }
                else{
                    water += maxLeft - height[left] ;
                }
                left++ ;
            }
            else{
                if(height[right] >= maxRight){
                    maxRight=height[right];
                }
                else{
                    water += maxRight - height[right] ;
                }
                right-- ;
            }
        }
        return water ;
    }
};