#include <bits/stdc++.h>
using namespace std;

// very very important question
// very important and unique approach

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* merge (Node* head1 , Node* head2){

    if(head1 == NULL){return head2 ;}
    if(head2 == NULL){return head1 ;}

    Node* dummyHead= new Node(-1) , *dummyTail = dummyHead ;
    while(head1 != NULL and head2!= NULL){

        if(head1 -> data <= head2 -> data){
            dummyTail -> bottom= head1 ;
            dummyTail = dummyTail-> bottom ; head1 = head1-> bottom ;
        }
        else{
            dummyTail -> bottom = head2 ;
            dummyTail = dummyTail -> bottom ; head2 = head2 -> bottom ;
        }
    }

    if(head1 != NULL){
        dummyTail -> bottom = head1 ;
    }
    if(head2 != NULL){
        dummyTail -> bottom = head2 ;
    }

    return dummyHead -> bottom ;

}

Node *flatten(Node *root){
    // Your code here
    
    if(root == NULL or root -> next == NULL){
        return root ;
    }

    root -> next = flatten(root -> next);

    root = merge (root , root -> next) ;

    return root ;
}