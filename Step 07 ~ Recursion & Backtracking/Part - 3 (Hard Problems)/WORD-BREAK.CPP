#include <bits/stdc++.h>
using namespace std ;

// motivation booster : gfg HARD did myself without any help in first attempt ✌

// recursion has only 1 trick : trust it

class Solution{
public:
    bool isValid (string temp , unordered_map<string, int> mp){
        return (mp.count(temp) == 1) ;
    }
    void recursion (string s, string temp ,int index, vector<string>&ans, unordered_map<string, int> mp){

        if(index == s.length()){
            temp.pop_back() ;
            ans.push_back(temp) ;
            return ;
        }

        for(int i= index ; i < s.length() ; i++){

            if(isValid(s.substr(index , i -index +1), mp)){
                string prev = temp ;
                temp += s.substr(index, i - index +1) ;
                temp += " ";

                recursion(s , temp , i +1 , ans , mp) ;
                temp = prev ;
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_map<string, int> mp ;
        for(auto x : dict){
            mp[x] = 1 ;
        }
        vector<string> ans ;
        recursion(s, "" , 0, ans, mp) ;

        return ans ;
    }
};