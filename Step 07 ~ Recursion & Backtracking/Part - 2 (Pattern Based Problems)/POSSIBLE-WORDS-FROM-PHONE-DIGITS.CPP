#include <bits/stdc++.h>
using namespace std;

// very well explained article
// https://www.geeksforgeeks.org/find-possible-words-phone-digits/

class Solution{
public:
    void recursion (vector<char> keypad[] , int input[] , int index , int n, string temp, vector<string>&ans){
        // base condition
        if(index == n){
            ans.push_back(temp) ; return ;
        }

        int curr_digit = input[index] ;
        int size = keypad[curr_digit].size() ;

        for(int i =0 ; i < size; i++){

            // One by one replace the digit with each character in the corresponding list and recur for next digit
            recursion(keypad , input ,index +1 , n , temp+keypad[curr_digit][i] , ans) ;

            // not picking is not an option because we have fixed size of the string we want
            // if we would follow pick and not pick then we would end up having extra string which would include empty strings, strings with 1 character, and so on
            // or if we want to follow pick and not pick then we need to have extra condition in our base condition that push when temp.length() == n
        }

    }
    vector<string> possibleWords(int a[], int N){
        // Your code here

        // keypad formation
        vector<char> keypad[]
        = { {}, // 0
            {}, // 1
            { 'a', 'b', 'c' }, // 2
            { 'd', 'e', 'f' }, // 3
            { 'g', 'h', 'i' }, // 4
            { 'j', 'k', 'l' }, // 5
            { 'm', 'n', 'o' }, // 6
            { 'p', 'q', 'r', 's' }, // 7
            { 't', 'u', 'v' }, // 8
            { 'w', 'x', 'y', 'z' } }; // 9

        vector<string> ans ;
        recursion(keypad, a , 0 , N , "" , ans) ;
        return ans ;

    }
};