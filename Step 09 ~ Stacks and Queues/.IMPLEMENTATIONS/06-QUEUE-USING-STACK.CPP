#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://rb.gy/6rfem

class Queue {
public:
    stack <int> s1, s2 ; // s1 would act as our queue
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.

        // if the element is first element of the queue -> just insert into the stack and return
        if(s1.empty()) {s1.push(val) ; return ;}

        // if its not the first element -> do some operations to get the correct sequence
        while(!s1.empty()) {
            s2.push(s1.top()) ; s1.pop() ;
        }
        s1.push(val) ;
        while(!s2.empty()) {
            s1.push(s2.top()) ; s2.pop() ;
        }
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if(s1.empty()) {return -1 ;}
        int t = s1.top() ; s1.pop() ; return t ;
    }

    int peek()
    {
        // Implement the peek() function here.
        if(s1.empty()){
            return -1 ;
        }
        return s1.top() ;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return s1.empty() ;
    }
};