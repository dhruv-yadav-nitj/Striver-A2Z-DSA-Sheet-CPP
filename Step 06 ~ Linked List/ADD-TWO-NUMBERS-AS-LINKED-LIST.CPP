#include <bits/stdc++.h>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/add-two-numbers/description/
// very simple and straight forward approach

// Time ~ O(max(m, n))
// Space ~ O(max(m, n))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        // code here

        ListNode* dummyHead = new ListNode() , *dummyTail = dummyHead ;
        int carry = 0;
        while(l1 != NULL or l2 != NULL or carry > 0){

            int sum = 0 ;
            if(l1 != NULL){
                sum += l1 -> val ;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val ;
                l2 = l2 -> next;
            }

            sum += carry ;
            dummyTail -> next = new ListNode(sum%10) ; carry = sum /10 ;
            dummyTail = dummyTail -> next ;
        }

        return dummyHead -> next ;

    }
};