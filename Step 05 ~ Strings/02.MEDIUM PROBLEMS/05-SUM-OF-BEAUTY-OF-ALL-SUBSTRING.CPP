#include <bits/stdc++.h>
using namespace std;

// brute force -> generate all the substrings and then calculate the beauty of each substring , etc. -> O(N3)

class Solution {
public:
    int beautySum(string s) {
        // Your code goes here
        int ans=0 , n = s.length() ;
        for(int i =0 ; i < n; i++) {
            vector<int> freq(26 , 0) ;
            for(int j = i ; j < n ; j++) {
                freq[s[j] - 'a']++ ;
                int maxi = 0 , mini = n ;
                for(int i =0 ; i < 26; i++) {
                    if(freq[i] > 0) {
                        maxi = max(maxi , freq[i]) ; mini = min(mini, freq[i]) ;
                    }
                }
                ans += maxi - mini ;
            }
        }
        return ans ;
    }
};

// gfg has some issues , try on leetcode
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/