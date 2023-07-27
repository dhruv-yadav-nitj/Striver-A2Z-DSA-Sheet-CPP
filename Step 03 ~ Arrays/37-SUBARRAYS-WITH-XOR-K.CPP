#include <bits/stdc++.h>
using namespace std;

// Pre-requisite : Problem #33 (similar approach)

// https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

int subarraysWithSumK(vector<int> a, int b) {
    // Write your code here

    int XOR = 0 ; int ans = 0 ; unordered_map<int, int> mp ; mp[0]++ ;

    for(int i =0  ;i < a.size() ; i++) {

        XOR = XOR ^ a[i] ;

        int x = XOR ^ b ;

        ans += mp[x] ;

        mp[XOR]++ ;
    }

    return ans ;

}