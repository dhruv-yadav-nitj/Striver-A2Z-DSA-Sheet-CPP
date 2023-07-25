#include <bits/stdc++.h>
using namespace std;

// [BRUTE FORCE] : Sort the arrays into decreasing order and generate all possible answers and get the max ones
// [OPTIMISED] : using Heap

// https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1

// Approach :
/* 
sort the arrays, we clearly know that the max sum we would get will be by adding the largest number out of the two arrays -> so just take the last indexes of the two arrays and push it into the maxheap (why max Heap -> since we want the largest numbers to be chosen which would be on the top in a max heap) -> take a set and insert the {i, j} into it (to avoid taking duplicates) -> if at any point the ans.size becomes k -> just return the ans
*/

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here

        sort(A.begin() , A.end()) ; sort(B.begin() , B.end()) ;

        priority_queue<pair<int, pair<int,int>>> pq ; vector<int> ans ; set<pair<int,int>> st;

        int i = N -1 , j= N-1 ; st.insert({i, j}); pq.push({A[i] + B[j] , {i, j}}) ;

        while(!pq.empty()) {
            auto it = pq.top() ; pq.pop();
            int sum = it.first ; i = it.second.first, j = it.second.second ;
            ans.push_back(sum) ;

            if(ans.size() == K) {return ans ;}

            int r1, c1, r2, c2; 
            r1 = i-1, c1= j , r2 = i, c2= j-1 ;

            if(r1 >= 0 and c1 >= 0 and !st.count({r1, c1})) {
                pq.push({A[r1]+B[c1] , {r1, c1}}) ;
                st.insert({r1, c1}) ;
            }

            if(r2 >= 0 and c2 >= 0 and !st.count({r2, c2})) {
                pq.push({A[r2]+B[c2] , {r2, c2}}) ;
                st.insert({r2, c2}) ;
            }
        }

        return {-1} ;
    }
};