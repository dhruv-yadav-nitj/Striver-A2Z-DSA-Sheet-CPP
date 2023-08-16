#include <bits/stdc++.h>
using namespace std;

// IMPORTANT PROBLEM
// ITS LOGIC IS VERY EASY -> BUT IMPLEMENTATION IS QUITE LENGTHY

// https://leetcode.com/problems/lru-cache/description/

// using linked list since we need O(1) time in get and put function

class Node {
public:
    int key, value ; Node *prev, *next ;
    Node (int data, int value) {
        this ->key = data ; this -> value= value ;
        this -> prev = NULL ; this -> next = NULL ;
    }
};

class LRUCache {
public:

    unordered_map<int, Node*> mp ; int c ; Node *head, *tail;

    LRUCache(int capacity) {
        this->c = capacity ;
        this -> head = new Node(-1, -1) ;
        this -> tail = new Node(-1, -1) ;
        head -> next = tail ; tail -> prev = head ;
    }

    int get(int key) {
        
        if(mp.count(key)) {

            Node *curr = mp[key] ;

            // update the location and place it next to head

            curr -> prev -> next = curr -> next ;
            curr -> next -> prev = curr -> prev ;

            curr -> next = head -> next ; head -> next -> prev = curr ;
            curr -> prev = head; head -> next = curr ;

            return curr -> value ;

        }
        else{
            return -1 ;
        }

    }

    void put(int key, int value) {

        // page hit condition
        if(mp.count(key)) {

            Node *curr = mp[key] ;

            // update the location and place it next to head

            curr -> prev -> next = curr -> next ;
            curr -> next -> prev = curr -> prev ;

            curr -> next = head -> next ; head -> next -> prev = curr ;
            curr -> prev = head; head -> next = curr ;
            
            // update the value according to the updated data
            curr -> value = value ;
        }
        else{

            // page fault condition
            if(mp.size() < c) {
                // if our memory is not yet filled -> simply add new data next to head

                Node* curr = new Node (key, value) ;

                head -> next -> prev = curr ; curr -> next = head -> next ;
                head -> next = curr; curr -> prev = head ;

                mp[key] = curr ;

            }
            else{

                // if our memory is completely filled -> we need to remove the data which is nearest to tail and then add the new data next to head

                Node* lru = tail -> prev ;

                lru -> prev -> next = lru -> next ; lru -> next -> prev = lru -> prev ;
                mp.erase(lru -> key) ; delete(lru) ;

                Node* curr = new Node(key, value) ;
                curr -> next = head -> next ; head -> next -> prev = curr ;
                head -> next = curr ; curr -> prev = head ;
                mp[key] = curr ;
            }
        }
    }
};