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
    int getNthFromLast(Node *head, int n){
        // code here

        int  l =0 ; Node* temp = head ;
        while(temp != NULL){
            l++ ; temp = temp -> next ;
        }

        if(n > l){ // if deletion is not possible
            return -1 ;
        }

        int k = (l- n +1) ; // nth node from last is kth from start (remember, its a formula)

        int count =1 ;
        while(count < k){
            head = head -> next ; count++ ;
        }

        return head -> data ;

    }
};