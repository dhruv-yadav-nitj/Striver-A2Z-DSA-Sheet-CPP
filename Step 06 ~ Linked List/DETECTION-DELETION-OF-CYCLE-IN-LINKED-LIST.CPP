// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data; Node* next;
    
    Node(int val){
        data = val; next = NULL;
    }
};

class Solution{
public:
    void removeLoop(Node* head){
        // code here
        // just remove the loop without losing any nodes

        if(!head or !(head -> next)){
            return ;
        }

        // step 1 : detection of cycle
        Node* slow= head , *fast= head;
        while(fast != NULL and fast -> next != NULL){
            slow= slow-> next ; fast = fast -> next -> next ;

            if(slow == fast){
                break;
            }
        }

        if(slow != fast){
            return ; // means no cycle present
        }

        // removal of cycle

        slow= head ;

        if(slow == fast){

            while(fast -> next != slow){

                fast = fast -> next ;                
            }
        }
        else{
            while(slow -> next != fast -> next){
                slow = slow -> next ; fast = fast-> next ;
            }            
        }

        fast -> next = NULL ;        
    }
};

// This same algo can be used to solve many other questions on the Cycle in Linked List like first node in cycle, length of cycle, etc