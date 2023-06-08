#include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data; Node * next; Node * prev;
    Node (int x){
        data=x; next=NULL; prev=NULL;
    }
};

class Solution{
public:
    Node * removeDuplicates(struct Node *head){
        // Your code here

        // step 1 : first fix a head
        while(head!= NULL and head ->next != NULL and head -> data == head -> next -> data){
            head = head-> next ;
        }

        head -> prev = NULL ; // doubly linked list is connected to NULL from both sides

        if(head == NULL or head -> next == NULL){return head ;} // if the list becomes empty or remains only with single element then return

        Node* prev = head, *curr = head -> next ;
        while(curr != NULL){

            while(curr != NULL and curr -> next != NULL and curr -> data == curr -> next -> data){curr = curr -> next;}
            
            prev -> next = curr ;
            curr -> prev= prev ;
            prev = curr ; curr = curr -> next ;
        }

        return head ;
    }
};