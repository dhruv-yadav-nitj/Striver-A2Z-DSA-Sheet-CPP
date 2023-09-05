#include <bits/stdc++.h>
using namespace std;

// most asked interview question on linked list -> though bahut fuddu ques hain
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

struct Node {
    int data; Node *next; Node *arb;

    Node(int x) {
        data = x; next = NULL; arb = NULL;
    }
};

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        unordered_map<Node*, Node*> mp ; Node* temp = head ;
        while(temp) {
            mp[temp] = new Node(temp->data) ;
            temp = temp -> next ;
        }
        temp = head ;
        while(temp) {
            mp[temp]-> next = mp[temp-> next] ;
            mp[temp]-> arb = mp[temp->arb] ;
            temp = temp -> next ;
        }
        return mp[head]; 
    }

};