#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://rb.gy/c07su

// Stack implementation using 2-Queues is very easy.

// Implment Stack using Single Queue.
class Stack {
public:
    queue<int> st ; // this queue would be made to work as stack
    Stack()
    {
        // Implement the Constructor.
    }

    int getSize()
    {
        // Implement the getSize() function.
        return st.size() ;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return st.empty() ;
    }

    void push(int element)
    {
        // Implement the push() function.
        st.push(element) ;
        int size= st.size() ; size -=1 ;
        while((size)--) {
            st.push(st.front()) ; st.pop() ;
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if(st.empty()) {
            return -1 ;
        }
        else {
            int temp = st.front() ; st.pop() ; return temp ;
        }
    }

    int top()
    {
        // Implement the top() function.
        if(st.empty()) {
            return -1 ;
        }
        else{
            return st.front() ;
        }
    }
};