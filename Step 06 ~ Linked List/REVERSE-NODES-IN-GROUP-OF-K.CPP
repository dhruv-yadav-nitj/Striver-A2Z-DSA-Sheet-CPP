#include <bits/stdc++.h>
using namespace std ;

// very important question for interviews

// this same problem done by me using extra space
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?page=1&status[]=unsolved&sortBy=submissions

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Optimised Approach -> HARD to explain
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // code here

        if(head == NULL or head -> next == NULL){
            return head ;
        }

        ListNode* dummy = new ListNode(-1) ; dummy ->next= head ;
        ListNode* prev , *curr , *fwd ;

        int count=1 ;
        ListNode* temp = head ;
        while(temp -> next != NULL){
            temp= temp-> next ; count++ ;
        }

        prev = dummy ;
        while(count >= k){
            curr = prev -> next ;
            fwd = curr -> next ;

            for(int i =1 ; i < k ;i++){

                curr -> next = fwd -> next ;
                fwd -> next = prev -> next ;
                prev -> next = fwd ;
                fwd = curr -> next ;
            }
            prev = curr ; count -= k ;
        }

        return dummy -> next ;
        
    }
};