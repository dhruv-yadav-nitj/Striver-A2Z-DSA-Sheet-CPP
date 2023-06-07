#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data; struct Node* next;

    Node(int x){
        data = x; next = NULL;
    }
};

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here

        Node* oddHead = new Node(-1) , *evenHead = new Node(-1) ;
        Node* oddTail = oddHead, *evenTail = evenHead ;

        while(head != NULL){

            Node* temp= head ; head = head -> next ; temp -> next = NULL ;

            if(temp -> data%2==0){
                evenTail -> next = temp ;
                evenTail= evenTail -> next ;
            }
            else{
                oddTail -> next= temp ;
                oddTail = oddTail -> next ;
            }
        }

        evenTail -> next = oddHead ->next ;
        return evenHead -> next ;
    }
};