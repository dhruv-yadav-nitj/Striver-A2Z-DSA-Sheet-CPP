#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class TrieNode{ // --> since trie does not exist as stl --> we need to make trie --> so either we can use struct or we can use class in c++ to make trie node

public:
    char data ; TrieNode* children[26] ; bool isTerminal ; // --> a trie node has three things --> addrees to its children , a letter as its data , and a bool data which tells us that whether this node is the end of a word or not --> by default we use keep false but when a word ends we use make it true

    // constructor
    TrieNode(char ch){
        data = ch ;
        for(int i =0 ;i < 26 ; i++){
            children[i] = NULL ; // --> by default we keep all the children as NULL and isTerminal as false
        }
        isTerminal = false ;
    }
};

class Trie{
public:
    TrieNode* root; // hr ek trie ka ek root hoga --> to ye whi hain

    // constructor for root node
    Trie(){
        root = new TrieNode('\0') ; // start the root node with NULL character
    }

    void insertWord(TrieNode* root , string word){ // --> we can insert words in a trie --> this function does that

    // we are using recursion to implement this function --> but this can also be done using for loop

        // base condition
        if(word.length() == 0){
            root -> isTerminal = true ; // if the word length is zero this means this is the end of the word --> so no we can make the terminal of this trie node as true
            return ;
        }

        TrieNode *child ;

        char key = word[0] ; tolower(key) ; // ho skta hain capitals mein ho ya small mein ho jisme bhi ho hm to lower case mein consider kr rhe

        if(root -> children[key - 'a'] != NULL){
            // agar root k paas ye letter phle se maujood hain then sirf aage badh jaao
            root = root -> children[key - 'a'] ;
        }
        else{
            child = new TrieNode(key) ;
            root -> children[key - 'a'] = child ;
        }

        // recursion
        insertWord(child, word.substr(1)); // ab agla node to child hoga
    }

    void insert(string word){
        insertWord(root, word) ;
    }

    bool searchWord(TrieNode* root, string word){
        // code here

        // base condition
        if(word.length() == 0){
            // meaning ki agar word ki length zero ho gyi hain then --> jis node pr khade ho wha ka isTerminal true hain then ye word shi mein exist krti hain
            return root -> isTerminal;
        }

        TrieNode* child ;
        
        char key = word[0] ; tolower(key) ;
        if(root -> children[key - 'a'] != NULL){
            // means this letter exists in the trie --> then move to the next node
            child = root -> children[key - 'a'] ;
        }
        else{return false ;}

        // recursion call
        return searchWord(child, word.substr(1)) ;
    }

    bool search(string word){return searchWord(root, word) ;}

    // in erase we can simply make the endTerminal of that word as false
    void eraseWord(TrieNode* root, string word){
        // base condition --> same as search
        if(word.length() ==0){
            if(root -> isTerminal){
                root -> isTerminal = false ;
            }
        }

        TrieNode* child ;
        char key = word[0] ; tolower(key) ;
        if(root -> children[key - 'a'] != NULL) {
            child = root -> children[key - 'a'] ;
            eraseWord(child , word.substr(1)) ;
        }
    }

    void erase(string word){
        eraseWord(root , word) ;
    }
};

int main(int argc, char const *argv[])
{
    Trie *trie =  new Trie() ; // initialising a trie
    trie -> insert("hello") ;

    if(trie -> search("hello")){
        cout << "Present" << endl ;
    }
    else{cout << "Not Present" ;}

    // erase function --> if erase function if begin applied for a word then we can assume that this word actually exist
    trie -> erase("hello") ;

    if(trie -> search("hello")){
        cout << "Present" << endl ;
    }
    else{cout << "Not Present" ;}

    return 0;
}
