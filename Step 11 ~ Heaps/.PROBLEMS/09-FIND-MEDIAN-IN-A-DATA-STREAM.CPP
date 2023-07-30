#include <bits/stdc++.h>
using namespace std;

// best example to understand this problem  2 4 3 7 as data stream

class MedianFinder {
public:
    priority_queue<int> left; priority_queue<int, vector<int> , greater<int>> right ;
    // left -> max Heap and right -> min Heap
    MedianFinder() {
        // code here

        // no use

    }

    // we have designed our system such that the left has size always either 1 greater than or equal to the size of right

    void addNum(int num) {
        // code here

        if(left.empty() and right.empty()) {

            // if both the heaps are empty -> simple push into max heap
            left.push(num) ;
        }

        else if (left.size() == right.size()) {

            // if both the heaps have equal size -> we need to push the element such that size of left becomes 1 greater than size of right

            if(num < right.top()) {
                left.push(num) ;
            }
            else{
                left.push(right.top()) ; right.pop() ; right.push(num) ;
            }
        }

        else{

            // means the left has size greater than right -> now we would try to level up the sizes of both the heaps

            if(right.empty()) {
                
                // if right is empty
                
                if(num > left.top()) {
                    right.push(num) ;
                }
                else{
                    right.push(left.top()) ; left.pop() ; left.push(num) ;
                }
            }

            // level up the sizes

            else if(num < left.top()) {
                right.push(left.top()) ; left.pop() ;
                left.push(num) ;
            }

            else{
                right.push(num) ;
            }

        }

    }

    double findMedian() {
        // code here

        int l = left.size() , r = right.size() ;

        if(l > r) {
            // means odd size of data stream
            return (double)(left.top()) ;
        }
        else{
            // means even size of data stream
            return (double)(left.top() + right.top()) /(double)2.0;
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */