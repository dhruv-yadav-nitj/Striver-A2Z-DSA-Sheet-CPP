#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;struct Node *next;Node(int x) {
        data = x;next = NULL;
    }

};

class Solution{
public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head){
        // your code here

        if(head == NULL){return -1 ;}

        Node* slow= head , *fast = head ;
        while(fast != NULL and fast -> next != NULL){
            slow= slow -> next ; fast = fast -> next -> next ;

            if(slow == fast){
                break;
            }
        }

        if(slow != fast){
            return -1 ;
        }


        slow = head ;
        if(slow== fast){

            return head -> data ;
        }
        else{

            while(slow -> next != fast -> next){
                slow = slow -> next ; fast = fast -> next ;
            }
        }

        return slow -> next -> data ;

    }
};