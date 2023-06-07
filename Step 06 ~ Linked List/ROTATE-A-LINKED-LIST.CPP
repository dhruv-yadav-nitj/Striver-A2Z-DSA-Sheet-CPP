#include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution{
public:
//Function to rotate a linked list.
    Node* rotate(Node* head, int k){
        // Your code here

        Node* temp = head , *tail =head ; int n =1 ;
        while(tail -> next != NULL){n++ ;tail = tail-> next ;}

        if(k==n){return head; }

        int count =1 ;
        while(count < k){
            temp = temp-> next; count++ ;
        }
        Node* new_head = temp -> next ;
        temp -> next = NULL ;
        tail -> next= head ;

        return new_head ;

    }
};