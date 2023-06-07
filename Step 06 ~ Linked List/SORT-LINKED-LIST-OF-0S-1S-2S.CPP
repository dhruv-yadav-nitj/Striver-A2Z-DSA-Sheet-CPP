#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;struct Node *next;Node(int x) {
        data = x;next = NULL;
    }
};

// approach #1 : using extra space (but was withing problem's O(n) limit)
class Solution{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here

        int arr[3]= {0} ;
        while(head != NULL){
            arr[head -> data]++ ; head = head -> next ;
        }

        Node* dummyHead = new Node(-1) ; Node* dummyTail = dummyHead ;
        while(arr[0] > 0){
            dummyTail -> next = new Node(0) ; dummyTail = dummyTail -> next ;
            arr[0]-- ;
        }
        while(arr[1] > 0){
            dummyTail -> next = new Node(1) ; dummyTail = dummyTail -> next ;
            arr[1]-- ;
        }
        while(arr[2] > 0){
            dummyTail -> next = new Node(2) ; dummyTail = dummyTail -> next ;
            arr[2]-- ;
        }

        return dummyHead -> next ;
        
    }
};

// approach #2 : optimised space --> using the dummy Nodes approach (used in separate odd even nodes in linked list problem)
class Solution{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        
        Node *head0 = new Node(-1) , *head1 = new Node(-1) , *head2 = new Node(-1) , *tail0= head0 , *tail1 = head1 , *tail2 = head2 ;

        while(head!= NULL){

            Node* temp= head ; head = head -> next ; temp -> next = NULL ;

            if(temp -> data == 0){
                tail0 -> next = temp ; tail0 = tail0 -> next ;
            }
            else if(temp -> data == 1){
                tail1 -> next = temp ; tail1 = tail1 -> next ;
            }
            else{
                tail2 -> next = temp ; tail2 = tail2 -> next ;
            }
        }

        if(head1 -> next != NULL){
            tail0 -> next = head1 -> next ;
        }
        else{
            tail0 -> next= head2 -> next ;
        }

        tail1 -> next = head2 -> next ;

        return head0 -> next ;

    }
};