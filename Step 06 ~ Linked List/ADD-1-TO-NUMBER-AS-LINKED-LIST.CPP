#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;struct Node *next;Node(int x) {
        data = x;next = NULL;
    }
};

// Time ~ O(n) and Space ~ O(1)

class Solution{
    public:

    Node* reverse(Node* head){

        if(head== NULL or head -> next== NULL){
            return head ;
        }

        Node* prev= NULL , *curr = head ;
        while(curr != NULL){
            Node* temp= curr -> next;
            curr -> next = prev ; prev = curr ; curr = temp ;
        }
        return prev ;

    }

    Node* addOne(Node *head){
        // Your Code here
        // return head of list after adding one

        // Approach:
        // reverse the linked list
        // add 1 to the head (which previously was the tail)
        // forward the carry to further nodes (if there is carry)
        // reverse the new linked list and return it

        if(head == NULL){
            return head ;
        }

        // step 1 : reverse the linked list
        head = reverse(head) ;

        // add 1 and forward the carry (if present)
        int carry=1 ; Node* curr = head, *prev ;
        while(curr != NULL){
            
            int temp= curr -> data + carry ;
            curr -> data = temp%10 ; temp /= 10 ; carry = temp ;
            prev = curr ;
            curr = curr -> next ;
        }


        if(carry > 0){
            prev -> next = new Node(carry) ;
        }

        return reverse(head) ;
    }
};