#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class TrieNode{
public:
    char data ; TrieNode* children[26] ; bool isTerminal ;
    int childCount ;

    // constructor
    TrieNode(char key){
        data = key ;
        for(int i= 0; i < 26 ; i++){
            children[i] = NULL ;
        }
        isTerminal = false ; // by default ye kisi bhi node ka false rkhenge
        childCount =0 ; // shuru mein to childCount zero hi rhega
    }
};

class Trie{
public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode('\0') ;
    }

    void insert(TrieNode* root , string word){

        // base condition
        if(word.length() == 0){
            root -> isTerminal = true ;
            return ;
        }
        TrieNode* child ;

        if(root -> children[word[0] - 'a'] != NULL){

            // means this element is present phle se
            child = root -> children[word[0] - 'a'] ;
        }
        else{
            child = new TrieNode(word[0] - 'a') ;
            root -> children[word[0] - 'a'] = child ;
            root -> childCount++ ;
        }

        insert(child , word.substr(1)) ;
    }
    void insertHelper(string word){insert(root , word) ;}

    void lcp (string word, string &ans){

        // dry run kro isko smjh aa jaaega

        TrieNode* curr = root ;

        for(int i =0 ;  i< word.length() ; i++){
            char ch = word[i] ;

            if(curr-> childCount > 1 or curr -> isTerminal){
                break ;
            }
            else{
                ans.push_back(ch) ;
                curr = curr -> children[ch - 'a'] ;
            }
        }
    }    
};

string longestCommonPrefix(vector<string> &arr, int n){
    // Write your code here
    Trie trie ;
    for(auto &&saxx: arr){
        trie.insertHelper(saxx) ;
    }

    string ans = "" ;
    trie.lcp(arr[0], ans) ; return ans ;
}