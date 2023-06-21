#include <bits/stdc++.h>
using namespace std;

// important problem
// its logic is very important to able to solve the next part of the problem

class Solution{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList){
        // Code here
        int n = startWord.length() ;

        // insert all the allowed words in a hash set to optimise the searching operation
        unordered_set<string> st ;
        for(auto it : wordList){
            st.insert(it) ;
        }

        // we would be using bfs to solve the problem

        queue<pair<string, int>> q ;
        q.push({startWord, 0}) ; // and to avoid repeativeness in the queue such that a word is not again pushed back in the queue we would delete the word from hash set which we are inserting in the queue

        while(!q.empty()){
            auto it = q.front() ; q.pop() ;
            string curr = it.first ; int count = it.second ;
            if(curr == targetWord){
                return count+ 1; 
            }

            for(int i=0; i< n ; i++){
                int original = curr[i] ;
                for(char k = 'a' ; k <= 'z' ; k++){
                    curr[i] = k ;
                    if(st.count(curr)){
                        q.push({curr, count+1}) ;
                        st.erase(curr) ;
                    }
                }
                curr[i]= original ;
            }
        }

        return 0 ;

    }
};