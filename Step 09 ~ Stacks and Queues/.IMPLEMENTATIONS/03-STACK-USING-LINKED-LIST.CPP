#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://rb.gy/k83k5

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack {
public:
    Node *head, *tail; int size =0 ; unordered_map <Node*, Node*> mp ;
    // unordered_map would be used to iterate back to the prev node when we would perform pop operation
    Stack()
    {
        // Write your code here
        this -> head = new Node(-1) ;
        tail = head ;
    }

    int getSize()
    {
        // Write your code here
        return size ;
    }

    bool isEmpty()
    {
        // Write your code here
        return (size ==0) ;
    }

    void push(int data)
    {
        // Write your code here
        size++ ; 
        Node*curr = new Node(data) ;
        tail ->next = curr ; mp[curr] = tail ;
        tail = tail ->next ;
    }

    void pop()
    {
        // Write your code here
        if(size ==0){return ;} // eat 5 star, do nothin
        Node* temp= tail ; tail = mp[tail] ; // backtrack to the prev node
        delete(temp) ;

        size-- ;
    }

    int getTop()
    {
        // Write your code here
        if(size ==0){return -1 ;}
        return tail ->data ;
    }
};