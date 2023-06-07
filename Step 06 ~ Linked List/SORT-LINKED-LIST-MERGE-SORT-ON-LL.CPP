#include <bits/stdc++.h>
using namespace std ;

// Problem Link:
// https://leetcode.com/problems/sort-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* findMid (ListNode* head){

        ListNode* slow = head, *fast = head -> next ;
        while(fast != NULL and fast -> next != NULL){
            slow = slow -> next ; fast = fast -> next -> next ;
        }

        return slow ;
    }

    ListNode* merge (ListNode* left, ListNode* right){

        if(left == NULL){return right ;}
        else if(right == NULL){return left ;}

        ListNode* dummyHead = new ListNode(-1) ; ListNode* dummyTail = dummyHead ;

        while(left != NULL and right != NULL){

            if(left-> val <= right -> val){

                dummyTail -> next = left ;
                dummyTail = dummyTail -> next ; left= left -> next ;
            }
            else{
                dummyTail -> next = right ; right = right -> next ;
                dummyTail = dummyTail -> next ;
            }
        }

        if(left != NULL){
            dummyTail -> next = left ;
        }
        if(right != NULL){
            dummyTail -> next = right ;
        }

        return dummyHead -> next ;

    }

    ListNode* sortList(ListNode* head){
        // code here

        // if the linked list is empty or has only single element
        if(head == NULL or head -> next == NULL){return head ;}

        ListNode* left , *mid , *right ;
        mid = findMid(head); left = head ; right = mid -> next ;
        mid -> next = NULL ;

        left = sortList(left) ; right = sortList(right) ;

        ListNode* result = merge(left , right) ;

        return result ;   
    }
};