#include <bits/stdc++.h>
using namespace std ;

// Initialising a Node , Insertion - at head, at tail , at kth position , Deletion - at head , at tail , at kth position , Length of Linked List , Search in Linked List

class ListNode{
public:
    int data ; ListNode* next ;
    ListNode (int data){
        this -> data = data ; next = NULL ;
    }
};


    void insertAtHead (ListNode*&head , int data){
        if(head == NULL){
            head = new ListNode(data) ;
        }
        else{
            ListNode* temp = new ListNode(data) ; temp -> next = head ; head = temp ;
        }
    }

    void insertAtTail (ListNode*&head , int data){
        if(head == NULL){
            head = new ListNode(data) ; return ;
        }

        ListNode* temp = head ;
        while(temp -> next != NULL){
            temp = temp ->next ;
        }
        temp -> next  = new ListNode(data) ;
    }

    void insertAtK (ListNode*&head , int k , int data){
        // suppose the total length of List is n and we have to insert a node at kth position and k <= n
        if(k==1){
            insertAtHead(head, data) ;
        }

        else{
            int count=1 ; ListNode* temp = head ;
            while(temp != NULL and count < k-1){
                temp = temp -> next ; count++ ;
            }
            ListNode* inserted = new ListNode(data) ; inserted -> next = temp ->next ; temp -> next = inserted;
        }
    }

    int length (ListNode* head){
        int count = 0 ;
        while(head != NULL){
            count++ ; head = head -> next ;
        }

        return count ;
    }

    void print (ListNode *head ){
        while(head != NULL){
            cout << head -> data << " " ; head = head -> next ;
        }cout << endl;
    }

    void deleete (ListNode*&head , int k){
        // suppose length of linked list is n and we have to delete kth node --> k <= n

        if(k == 1){
            // means delete the head node
            head = head -> next ; return ;
        }
        ListNode* prev= NULL , *curr = head ; int count =1 ;
        while(count < k and curr != NULL){

            count++ ; prev = curr ; curr = curr -> next ;
            prev -> next = curr -> next ; delete(curr) ;
        }
    }

    int search (ListNode* head , int data){
        int ans = 1 ;
        while(head != NULL){
            if(head -> data == data) {
                return ans ;
            }
            ans++ ; head = head -> next ;
        }

        return -1 ;

    }

int main () {
    ListNode* head= new ListNode(1) ; print(head) ;
    insertAtTail(head, 2) ; print(head) ;

    insertAtK(head , 2, 3) ; print(head) ; deleete(head , 2) ; print(head) ;
    cout << length(head) << endl ;

}