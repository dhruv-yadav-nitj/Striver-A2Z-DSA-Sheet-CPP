#include <bits/stdc++.h>
using namespace std;

// EASY BFS SOLUTION -> BUT HARD OPTIMISED SOLUTION

// approach #1 : using BFS intuition -> some kind of djikstra's algo u can say
class Solution {
public:
    int minJumps(int arr[], int n) {
        // Your code here

        // condition 1 : if the given array has only one element -> start is the end
        if(n ==1) {
            return 0 ;
        }

        // approach #1 : we can easily apply a bfs solution

        queue<pair<int,int>> q ; vector<int> jump (n , 1e9) ; // jump[i] -> denotes how much min jumps it takes to reach ith index
        q.push({0 , 0}) ; // <jump , index>
        jump[0] = 0 ;

        while(!q.empty() ){
            int jumps = q.front().first , index =q.front().second ; q.pop() ;

            if(index == n -1) {
                return jumps ;
            }

            for(int i =1 ; i <= arr[index] ; i++) {
                int j = index + i ;
                if(j < n and jumps +1 < jump[j]) {
                    jump[j] = jumps +1 ; q.push({jumps +1 , j}) ;
                }
            }
        }

        if(jump[n-1] == 1e9) {
            return -1 ;
        }
        else{
            return jump[n-1] ;
        }

    }
};
// giving TLE obviously -> we can do this problem in O(n)

// approach #2 >: GREEDY (same as BFS but optimised)
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int j =0 , maxReach =0 , count =0 ; // j would serve as the right pointer on our current window
        for(int i = 0; i < n -1 ; i++) { // i would be the left pointer of our current window
            maxReach = max(maxReach , i + arr[i]) ; // max jump we can take from current index
            if(i == j) { // if left pointer catches right pointer -> our current window is complete -> update the window (i.e., right pointer to maxReach)
                count++ ; // one window complete so increase the jump count
                j = maxReach ;
                if(j >= n -1) { // if the right pointer is out of the array or at the last index this means we reached the end
                    return count ;
                }
            }
        }
        
        // if not possible to reach then return -1
        return -1 ;
        
    }
};