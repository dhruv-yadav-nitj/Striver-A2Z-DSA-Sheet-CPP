#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK
// https://rb.gy/pv2xr

class Queue
{
    int front, rear;
    vector<int> arr; int n ;
public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr.resize(100001);
        this -> n = 100001 ;
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        rear = (rear +1)% n ;
        if(front == rear ){
            // overflow
        }
        else {
            arr[rear] = e ;
            if(front == -1) {
                // means it was the first element
                front = rear ;
            }
        }
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if(front == -1){
            // means the queue is empty
            return -1 ;
        }
        else{
            int temp = arr[front] ;
            if(front == rear) {
                // means the last element is to be removed
                front = rear = -1 ;
            }
            else{
                front = (front+1)%n ;
            }
            return temp ;
        }
    }
};