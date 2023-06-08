#include <bits/stdc++.h>
using namespace std ;

struct Node {
  int data; struct Node *next;
  Node(int x) {
    data = x; next = NULL;
  }
};

// https://www.codingninjas.com/codestudio/library/intersection-point-in-y-shaped-linked-lists

// approach #1 : using nested loop
// approach #2 : using hashmaps

// approach #3 : Optimised using Parallel traversals

int length (Node* head){

    int count =0 ;
    while(head != NULL){
        head = head -> next ; count++ ;
    }

    return count ;
}

int intersection (Node* head1 , Node* head2, int d){

    // such that length(head1) <= length(head2) always

    // move head2 to dth node
    while(head2 != NULL and d > 0){
        head2 =head2 -> next ; --d ;
    }

    while(head1 != NULL and head2 != NULL){
        if(head1 == head2){
            return head1 -> data ;
        }
        head1 = head1 -> next ; head2 = head2 -> next ;
    }

    // if no intersection --> return -1 ;
    return -1 ;

}

int intersectPoint(Node* head1, Node* head2){
    // Your Code Here
    int l1= length(head1) , l2 = length(head2) ;
    int d = abs(l1-l2) ;

    if(l1 <= l2){
        return intersection(head1, head2, d) ;
    }
    else{
        return intersection(head2 , head1, d) ;
    }
}