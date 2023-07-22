#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; Node *next; Node(int x) {
        data = x; next = NULL;
    }
};

class Solution {
public:
    Node *mergeKLists(Node *arr[], int K) {
        // Your code here
        priority_queue <pair<int,Node*> , vector<pair<int,Node*>> , greater<pair<int,Node*>>> pq ;

        // push the heads of all the linked list in the priority queue
        for(int i =0 ; i < K ; i++) {
            pq.push({arr[i]-> data , arr[i]}) ;
        }
        
        Node* dummyHead= new Node (-1) ; Node* temp = dummyHead ;

        while(!pq.empty()) {
            auto it = pq.top() ; pq.pop() ; int val = it.first ; Node* curr =it.second ;
            temp -> next = curr ; 

            if(curr -> next) {
                pq.push({curr-> next -> data , curr -> next}) ;
            }

            temp = temp -> next;
        }

        temp -> next = NULL ; return dummyHead -> next ;

    }
};