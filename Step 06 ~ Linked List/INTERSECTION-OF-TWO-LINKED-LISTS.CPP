#include <bits/stdc++.h>
using namespace std ;

// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

struct Node{
    int data;struct Node *next;Node(int x) {
        data = x;next = NULL;
    }
};

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
        Node* dummyHead = new Node(-1) , *dummyTail = dummyHead ;
        unordered_map<int, int> mp ;
        while(head2 != NULL){
            mp[head2 -> data] = 1 ; head2 = head2 -> next ;
        }
        
        while(head1 != NULL){
            
            if(mp[head1-> data]==1){
                dummyTail -> next = new Node(head1 -> data) ;
                dummyTail = dummyTail -> next ;
            }
            head1 = head1 -> next ;
        }
        return dummyHead -> next ;
        
    }
};