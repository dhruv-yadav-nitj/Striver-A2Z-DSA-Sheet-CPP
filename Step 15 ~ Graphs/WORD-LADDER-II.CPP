#include <bits/stdc++.h>
using namespace std;

// its extremely hard problem (there are few things which are hard to understand , better to view the striver's video on this problem very carefully)

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // code here

        unordered_set<string> st (wordList.begin() , wordList.end()) ;

        vector<vector<string>> ans ; vector<string> used ;
        queue<vector<string>> q; int level = 0 ;

        q.push({beginWord}) ; used.push_back(beginWord) ;

        // traversal (modified bfs algo)
        while(!q.empty()){
            vector<string> curr = q.front() ; q.pop() ;

            if(curr.size() > level){
                for(auto x: used) {
                    st.erase(x) ;
                }

                ++level ;
            }

            string lastWord = curr.back() ;
            if(lastWord == endWord){
                
                if(ans.size() ==0 ){
                    ans.push_back(curr) ;
                }
                else if(ans[0].size() == curr.size()){
                    ans.push_back(curr) ;
                }
                else{
                    return ans ;
                }
            }

            for(int i =0; i < lastWord.length() ; i++){

                string temp = lastWord ;
                for(char k = 'a' ; k <= 'z'; k++){
                    temp[i] = k ;
                    if(st.count(temp)){
                        curr.push_back(temp) ; q.push(curr) ;
                        used.push_back(temp) ;

                        curr.pop_back() ;
                    }
                }
            }
        }

        return ans ;
        
    }
};