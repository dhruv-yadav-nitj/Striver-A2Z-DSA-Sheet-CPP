#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://shorturl.at/duvxP

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

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

struct Queue
{
    Node *front;
    Node *rear;
    void push(int);
    int pop();

    Queue()
    {
        front = rear = NULL;
    }
};

void Queue::push(int x) {
    // Write Your Code Here
    Node* curr = new Node (x) ;
    if(rear == NULL) {
        rear = curr ; front = curr ;
    }
    else{
        rear ->next = curr ; rear = curr ;
    }
}

int Queue::pop() {
    // Write Your Code Here
    if(!front){
        return -1 ;
    }
    else{
        int fr = front ->data ;
        front = front -> next ;
        if(!front){
            // if the list gets empty
            rear = front ;
        }
        return fr ;
    }
}