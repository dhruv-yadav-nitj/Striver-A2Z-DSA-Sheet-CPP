#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://rb.gy/00nkd

// the ques is very very much simple just watch this video to understand LRU (Least Recently Used) Algorithm
// https://www.youtube.com/watch?v=dYIoWkCvd6A
// for further help : https://youtu.be/U8K1cpdMN4I

class Solution {
public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        
        unordered_map<int,int>mp ; unordered_set<int> st ;
        // i would use set to denote the memory of CPU and hashmap to store the index of currenly stored pages in CPU  
        int count(0) ; // count -> denotes the number of page faults

        for(int i =0 ;i < N ; i++) {
            
            int page = pages[i] ; // current task

            // if the current element is already present in the memory (HIT Condition) -> just update the index of this element
            if(st.find(page) != st.end()) {
                mp[page] = i ;
            }
            else{
                // if its not present in the memory -> page fault condition
                count++ ;
                if(st.size() < C) { // if the memory has enough space -> simply insert it in the memory
                    st.insert(page) ; mp[page] = i ;
                }
                else{ // if the memory does not have space -> choose the element which occrured way before (least recently) -> using the hashmap (element with smallest index would be LRU)
                    int lru , index = INT_MAX ;
                    for(auto it: mp) {
                        if(it.second < index) {
                            lru = it.first, index= it.second ;
                        }
                    } // remove LRU from set and map -> and insert new element in the set and map
                    st.erase(lru) ; mp.erase(lru) ;
                    st.insert(page) ; mp[page] =i ;
                }
            }
        }

        return count ;

    }
};