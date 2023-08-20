#include <bits/stdc++.h>
using namespace std;

// HARD Level Implementation
// https://youtu.be/0PSB9y8ehbk?si=HkEE-soV4lgoGIu4
// https://github.com/striver79/SDESheet/blob/main/LFUCacheCppLeetcode

class Node {
public:
    int key , val , freq ; Node *prev, *next ;
    Node (int key, int val) {
        this -> key = key; this -> val = val;
        this -> prev = NULL ; this -> next = NULL ;
        this -> freq =1 ; // initialise the frequency with 1 when a node is created
    }
};

class List {
public:
    Node *head, *tail; int size ;
    List () {
        head = new Node (-1, -1) ; tail = new Node(-1, -1) ;
        head -> next = tail ; tail -> prev = head ; size = 0; // initial size is 0
    }

    void add (Node *node) {
        // always add at head
        node -> next = head -> next ;
        head -> next -> prev = node ;
        head -> next = node ; node -> prev = head ;
        size++ ;
    }

    void remove (Node *node) {
        node -> prev -> next = node -> next ;
        node -> next -> prev = node -> prev ;
        delete(node) ; --size ;
    }
};

class LFUCache {
public:
    map<int, List*> mpp1 ; map<int, Node*> mpp2 ;
    int capacity , minFreq , currSize ;
    LFUCache(int capacity) {
        this -> capacity = capacity ;
        this -> minFreq = 0 ; this -> currSize = 0 ;
    }

    void update (Node* node) {
        
        mpp2.erase(node->key) ;

        // when we are updating a node -> we are increasing its frequency -> so we need to first remove this node from the current frequency wala list

        mpp1[node->freq]->remove(node) ;
        // if this node was the one and only one node in that frequency wala list we need to upgrade the minFrequency
        if(node -> freq == minFreq and mpp1[node -> freq]->size==0) {
            minFreq++ ;
        }

        List* nextHigherFreq = new List() ;
        if(mpp1.count((node->freq) +1)) {
            nextHigherFreq = mpp1[(node -> freq) +1];
        }

        node -> freq += 1;
        nextHigherFreq-> add(node) ; // add this node into the new frequency wla list
        mpp1[node -> freq] = nextHigherFreq ;
        mpp2[node->key] = node ;
    }

    int get(int key) {
        if(mpp2.count(key)){
            // if the given key is present in the memory -> update the status of its node and return the value
            Node* node = mpp2[key] ; int val = node -> val ;
            update(node) ;
            return val;
        }
        else{
            return -1 ;
        }
    }

    void put(int key, int value) {

        if(capacity ==0){return ;}

        if(mpp2.count(key)) {
            // page hit condition -> simply update the status of existing node
            Node* node = mpp2[key] ;
            node -> val = value;
            update(node) ;
        }
        else{
            // page fault condition -> the page to be put does not existed before
            // in this case -> we need to check if the memory is completely occupied or not

            // case 1 : it is completely occupied -> we need to remove the lru of min Freq list
            if(currSize == capacity) {
                // means hme panchayat krna  pdhega
                List *list = mpp1[minFreq] ;
                mpp2.erase(list -> tail -> prev -> key) ;
                mpp1[minFreq]->remove(list -> tail -> prev) ;
                currSize -=1 ;
            }
            currSize +=1 ; minFreq =1 ; // since a new node is to be added in the memory -> its freq would obviously be 1 -> which would be now the min Frequency

            List *list1 = new List() ;
            if(mpp1.count(minFreq)) {
                list1 = mpp1[minFreq] ;
            }

            Node* node = new Node(key, value) ;
            list1 -> add(node) ;
            mpp2[key] = node ;
            mpp1[minFreq] = list1 ;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */