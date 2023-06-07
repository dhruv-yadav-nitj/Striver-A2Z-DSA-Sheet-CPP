#include <bits/stdc++.h>
using namespace std ;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head){
    // Your Code Here

    Node* prev= NULL , *slow= head , *fast = head ;
    while(fast != NULL and fast -> next != NULL){

        prev = slow ; slow = slow -> next ; fast = fast -> next -> next ;

    }

    prev -> next = slow -> next ; delete(slow) ;

    return head ;

}