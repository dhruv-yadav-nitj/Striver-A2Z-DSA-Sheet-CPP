#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://rb.gy/p30t0

// Implementation of Stack is very easy as compared to Implementation of Queue, bcz in Stack its unidirectional (we insert and remove from one side only), we have to maintain only one pointer i.e., top but in queue we need to manage both pointers front and end

class Stack {
    int topp = -1 ; vector<int> arr ; int n ;
public:
    Stack(int capacity) {
        this -> n = capacity ;
        arr.resize(n) ;
    }

    void push(int num) {

        if(!isFull()) {
            arr[++topp]=num ;
        }
        else{
            // stack overflow
        }
    }

    int pop() {
        if(isEmpty()) {
            return -1 ;
        }
        else{
            int temp = arr[topp] ; topp-- ; return temp ;
        }
    }
    
    int top() {
        if(isEmpty()) {
            return -1 ;
        }
        else{
            return arr[topp] ;
        }
    }
    
    int isEmpty() {
        if(topp==-1){return 1;}else{return 0;}
    }
    
    int isFull() {
        if(topp==n-1){return 1;}else{return 0;}        
    }
};