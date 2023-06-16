#include <bits/stdc++.h>
using namespace std;

// leetcode version
// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrome (string s){
        int start = 0 , end= s.length()- 1 ;
        while(start <= end){
            if(s[start] != s[end]){
                return false ;
            }
            start ++ , end-- ;
        }
        return true ;
    }

    void recursion (string s, int index, vector<string> temp , vector<vector<string>>&ans){

        if(index == s.length()){
            ans.push_back(temp) ;
            return ;
        }

        for(int i = index ; i < s.length() ; i++){
            // consider the substring from index to i
            string tempo = s.substr(index , i - index +1) ;

            // if the taken substring is a palindrome then push it into the temp vector and then check for the palindrome partitioning from index i +1 (where the current substring ended)
            if(isPalindrome(tempo)){
                temp.push_back(tempo) ;
                recursion(s , i +1 , temp , ans) ;

                // if the right part of the string was not a palindrome then pop this current part as it is of no use to us
                // backtrack
                temp.pop_back() ;
            }
        }

    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        recursion(s, 0, {} , ans) ; return ans ;
    }
};

// gfg version
// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

class Solution{
public:
    int ans = 1e9 ;
    bool isPalindrome (string s){
        int start= 0 , end  =s.length() - 1 ;
        while(start <= end){
            if(s[start] != s[end]){
                return false ;
            }

            start ++ , end-- ;
        }
        return true ;
    }

    void recursion (string s, int index, vector<string> temp){
        if(index == s.length()){
            if(temp.size() > 0 and ans > temp.size()-1){
                ans = temp.size()-1 ;
            }
            return ;
        }

        for(int i = index ; i < s.length() ; i++){
            string tempo = s.substr(index ,i - index +1) ;
            if(isPalindrome(tempo)){
                temp.push_back(tempo) ;

                recursion(s , i +1 , temp) ;

                // backtrack
                temp.pop_back() ;
            }
        }

        // return
    }

    int palindromicPartition(string str){
        // code here

        recursion(str, 0 , {}) ;return ans ;
    }
};

// the code works well on leetcode but gives TLE on gfg because at gfg we need to submit the DP solution of the problem