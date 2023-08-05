#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// very very good question

class TrieNode{
public:
    char data ; TrieNode* children[26] ; bool isTerminal ;
    TrieNode(char key){
        data = key ;
        for(int i =0 ; i < 26 ; i++){
            children[i] = NULL ;
        }
        isTerminal = false ;
    }
};

class Trie{
public:
    TrieNode* root ;

    // constructor
    Trie(){
        root = new TrieNode('/0') ;
    }

    void insertWord(TrieNode* root, string word){
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
        insertWord(root, word) ;
    }



    // these two are the main functions of this program

    void printSuggestions(TrieNode* curr , vector<string>&temp, string prefix){
        // code here

        if(curr -> isTerminal){
            temp.push_back(prefix) ;

            // normally sochne pr lgega ki yha se return krna chaiye but yha se return nhi krenge because aisa bhi ho skta hain ki us line mein ek word phle hi khmt ho jaae aur ek word hain jo baad mein end ho rha ho --> so agar hm yha se return kr gye then baad waala word nhi le paaenge

            // example --> coding and cod
            // d pr aate hi wha pr isTerminal true ho jaaega and agar hmne yha return likh diaa then hm d k aage means i aur n aur g nhi le paaenge
        }


        for(char ch = 'a' ; ch <= 'z' ; ch++){
            // code-here
            TrieNode* next = curr -> children[ch - 'a'] ;

            if(next != NULL){
                prefix += ch ; printSuggestions(next, temp , prefix) ;
                prefix.pop_back() ;
            }
        }
    }

    vector<vector<string>> returnSuggestions(string s){
        vector<vector<string>> ans ;
        TrieNode *prev = root , *curr ; // take two nodes prev and curr
        string prefix = "" ; // take this string jisme hm har ek iteration k saath push back krte jaaenge
        for(int i=0 ; i < s.length() ; i++){ // ab jaise hme s= cod mila then ek baar prefix mein c hoga then co then cod
            prefix += s[i] ; char lastKey = s[i] ;
            curr = prev -> children[lastKey - 'a'] ;
            if(curr == NULL){
                break ;
            }
            else{
                vector<string> temp ;
                printSuggestions(curr, temp, prefix) ; ans.push_back(temp) ;
                prev = curr ;
            }
        }
        return ans ;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    //  Write your code here.
    Trie trie ;
    for(auto &&x: contactList){
        trie.insert(x) ;
    }
    return trie.returnSuggestions(queryStr) ;
}