#include <bits/stdc++.h>
using namespace std;


// [IMPORTANT] [HARD]

// https://leetcode.com/problems/find-median-from-data-stream/description/

// Explanation : https://youtu.be/1LkOrc-Le-Y

class MedianFinder {
public:

    priority_queue<int> maxHeap; priority_queue <int, vector<int>, greater<int>> minHeap ;
    MedianFinder() {
        // no use
    }
    
    void addNum(int num) {

        // if both the heaps are empty -> push into maxHeap
        if(maxHeap.empty() and minHeap.empty()) {maxHeap.push(num) ;}
        // if both the heaps have same size -> then compare in which heap do we need to add the data
        else if(maxHeap.size() == minHeap.size()) {
            int l = maxHeap.size(), r = minHeap.size() ;
            if(num < minHeap.top()) {
                maxHeap.push(num) ;
            }
            else{
                maxHeap.push(minHeap.top()) ; minHeap.pop() ; minHeap.push(num) ;
            }
        }
        else{

            // case 1
            if(minHeap.size() ==0) {
                if(num > maxHeap.top()) {
                    minHeap.push(num) ;
                }
                else{
                    minHeap.push(maxHeap.top()) ; maxHeap.pop() ;
                    maxHeap.push(num) ;
                }
            }
            else if(num >= minHeap.top()) {
                minHeap.push(num) ;
            }
            else{
                if(num < maxHeap.top()) {
                    minHeap.push(maxHeap.top()) ; maxHeap.pop() ;
                    maxHeap.push(num) ;
                }
                else{
                    minHeap.push(num) ;
                }
            }
        }
    }
    
    double findMedian() {

        int l=  maxHeap.size() , r = minHeap.size() ;
        if(l > r) {
            return double(maxHeap.top()) ;
        }
        else{
            return (double(maxHeap.top()) + double(minHeap.top())) /2 ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */