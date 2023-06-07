#include <bits/stdc++.h>
using namespace std ;

class ListNode {
public:
    int data ; ListNode* prev , *next ;

    ListNode(int data){
        this -> data = data ; prev = NULL ; next = NULL ;
    }
};

void insertAtHead (ListNode*&head , int data){
    if(head == NULL){
        head = new ListNode(data) ;
        return ;
    }

    ListNode* temp = new ListNode(data) ; temp -> next = head ; head= temp ;
}

void insertAtTail (ListNode*&head , int data){

    if(head == NULL){
        insertAtHead(head, data) ;
    }
    else{

        ListNode* curr = head ;
        while(curr -> next != NULL){
            curr = curr ->next ;
        }

        ListNode* temp = new ListNode(data) ;
        temp -> prev = curr ; temp -> next = curr -> next ; curr -> next = temp ;
    }
}

void insertAtK (ListNode* &head, int k , int data){
    // assuming length of List is n and we have to insert a node at kth position --> k <= n always
    if(k==1){
        insertAtHead(head, data) ;
        return ;
    }
    int count= 1 ; ListNode* temp =head;
    while(count < k and temp != NULL){
        count++ ; temp = temp-> next ;
    }

    ListNode* curr= new ListNode(data) ;
    temp -> prev -> next = curr ;
    curr -> prev = temp -> prev ; temp -> prev = curr ; curr -> next = temp ;
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

void deleete (ListNode*&head, int k){
    // assuming length of list to be n and we have to delete the kth node --> we have k <= n

    if(k==1){
        // means we have to delete the head
        if(head -> next == NULL){head = NULL ;} // it may happen the list has only one node --> in that case the new head would be NULL
        else{
            head -> next -> prev = NULL ; head = head -> next;
        }
    }
    else{
        int count =1 ; ListNode* prev= NULL , *curr  =head ;
        while(curr != NULL and count < k-1){
            curr = curr -> next ; count++ ;
        }
        // we have to delete the node curr -> next
        ListNode* fwd = curr -> next -> next ; delete(curr ->next);
        if(fwd != NULL){
            curr -> next = fwd ; fwd -> prev = curr ;
        }
        else{
            curr -> next = fwd ;
        }
    }
}

// Reverse a Doubly Linked List --> Important
ListNode* reverse (ListNode*&head) {

    // if the list is empty or has only one element
    if(head == NULL or head -> next == NULL){
        return head ;
    }

    ListNode* back= NULL , *curr = head ;
    while(curr != NULL){

        back = curr -> prev ; 
        curr ->prev = curr ->next ; curr -> next = back ; // reverse the directions of prev and next pointers

        curr = curr -> prev ; // move forward the curr pointer
    }

    return back -> prev ;
}

int main (){

    ListNode* head = new ListNode(1) ;
    insertAtTail(head ,2) ; insertAtTail(head ,3) ;

    print(head);

    insertAtHead(head , 4) ; print(head) ; deleete(head , 1) ; print(head) ;

    insertAtK(head , 2, 4) ; print(head) ;

    cout << length(head) << endl ;
    
    deleete(head , 4) ; print(head) ;

}