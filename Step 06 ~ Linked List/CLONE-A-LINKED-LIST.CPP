#include <bits/stdc++.h>
using namespace std;

// most asked interview question on linked list

struct Node {
    int data; Node *next; Node *arb;

    Node(int x) {
        data = x; next = NULL; arb = NULL;
    }
};

class Solution{
public:
    Node *copyList(Node *head){
        // Write your code here

        unordered_map<Node*, Node*> mp ;
        Node* temp = head ;
        while(temp != NULL){
            Node* clone = new Node(temp -> data) ;
            mp[temp] = clone ;
            temp = temp-> next ;
        }

        Node* curr= head ;
        while(curr != NULL){

            Node* clone = mp[curr] ;
            if(curr -> next != NULL){
                clone -> next = mp[curr -> next] ;
            }
            else{
                clone -> next= NULL ;
            }

            if(curr -> arb != NULL){
                clone -> arb = mp[curr -> arb] ;
            }
            else{
                clone -> arb= NULL ;
            }

            curr = curr -> next ;
        }

        return mp[head] ;

    }
};