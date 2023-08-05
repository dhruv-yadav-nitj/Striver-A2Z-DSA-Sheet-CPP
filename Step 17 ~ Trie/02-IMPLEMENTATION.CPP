/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// it is clearly given that the word and prefix consists of lowerCase English Alphabets

class TrieNode{
public:
    TrieNode* children[26] ; char data ; bool isTerminal ; // ye cheeje to kisi bhi trieNode ki pehchaan hain to ye rhengi hi

    TrieNode(char ch){ // constructor
        data = ch ;
        for(int i=0 ; i < 26; i++){
            children[i] = NULL ;
        }

        isTerminal = false ;
    }
};

class Trie {
public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode('\0') ;
    }

    void insertWord(TrieNode* root, string word){
        // base condition
        if(word.length() == 0){
            root -> isTerminal = true ; return ;
        }

        TrieNode* child ;

        if(root -> children[word[0] - 'a'] != NULL){
            child = root -> children[word[0] - 'a'] ;
        }
        else{
            child = new TrieNode(word[0]) ;
            root -> children[word[0] - 'a'] = child ;
        }

        insertWord(child , word.substr(1)) ;
    }
    
    void insert(string word){

        insertWord(root , word) ;
        
    }

    bool searchWord(TrieNode* root , string word){
        if(word.length() == 0){
            return root -> isTerminal ;
        }

        TrieNode* child ;

        if(root -> children[word[0] - 'a'] != NULL){

            child = root -> children[word[0] - 'a'] ;
            return searchWord(child , word.substr(1)) ;
        }
        else{
            return false ;
        }
    }
    
    bool search(string word) {

        return searchWord(root , word) ;
        
    }

    bool doesStartWith(TrieNode* root , string prefix){

        // base condition
        if(prefix.length() == 0){
            return true ;
        }

        if(root -> children[prefix[0] - 'a']) {
            return doesStartWith(root -> children[prefix[0] - 'a'] , prefix.substr(1)) ;
        }
        else{
            return false ;
        }        
    }
    
    bool startsWith(string prefix) {

        return doesStartWith(root , prefix) ;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
