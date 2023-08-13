#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack {
    int topp=0, end=-1, n=0; vector<int> arr;
public:
    Stack(int capacity) {
        arr.resize(capacity) ;
        n = capacity ;
    }

    void push(int num) {
        if(!isFull()) {
            end = (end+1)%n ;
            arr[end] = num ;
        }
    }

    int pop() {
        if(isEmpty()) {return -1 ;}
        int temp = arr[topp] ;
        topp = (topp +1)%n ; if(topp > end) {topp = 0, end = -1 ;}
    }
    
    int top() {
        if(!isEmpty()) {
            return arr[topp] ;
        }
    }
    
    int isEmpty() {
        if(end==-1){
            return 1 ; 
        }
        else{
            return 0 ;
        }
    }
    
    int isFull() {
        if((end+1)%n == topp){
            return 1 ;
        }
        else{
            return 0 ;
        }
    }
};
