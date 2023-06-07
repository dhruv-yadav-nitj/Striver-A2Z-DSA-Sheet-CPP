#include <bits/stdc++.h>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/remove-linked-list-elements/description/

// Approch : first fix a head --> that is delete all the heads with the given target value so that we can secure our ans to be returned --> after fixing head --> move to further nodes and apply basics

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val){
        // code here

        if(head == NULL){return head ;}

        // step 1: fix a head : for eg in the case --> 2 -> 2-> 3 -> 5 -> 1 and target =2 
        while(head != NULL and head -> val == val){

            head = head -> next ;
        }
        // if linked list become empty
        if(head==NULL or head -> next == NULL){return head ;}

        ListNode* prev= head, *curr = head ;
        while(curr != NULL){
            if(curr -> val == val){
                ListNode* fwd = curr -> next ; prev-> next = curr -> next ;
                curr -> next = NULL ; curr = fwd ;
            }
            else{
                prev= curr ;
                curr = curr -> next ;
            }
        }

        return head ;
        
    }
};