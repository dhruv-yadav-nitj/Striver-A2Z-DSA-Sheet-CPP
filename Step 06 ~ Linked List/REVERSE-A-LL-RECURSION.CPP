#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* recursion (ListNode* head){

        if(!head or !(head -> next)){

            return head ;
        }

        ListNode* node = recursion(head -> next); // this would track the end of the list (our new head)

        head -> next ->next = head ; head ->next = NULL ; // based on very sharp observation
        return node ;

    }

    ListNode* reverseList(ListNode* head) {

        return recursion(head) ;

    }
};