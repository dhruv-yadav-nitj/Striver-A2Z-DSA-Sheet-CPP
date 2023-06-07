#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;struct Node *next;Node(int x) {
        data = x;next = NULL;
    }

};

int countNodesinLoop(struct Node *head)
{
    // Code here
        
    if(head == NULL){return 0 ;}

        Node* slow= head , *fast = head ;
        while(fast != NULL and fast -> next != NULL){
            slow= slow -> next ; fast = fast -> next -> next ;

            if(slow == fast){
                break;
            }
        }

        if(slow != fast){
            return 0 ;
        }


        slow = head ;
        if(slow== fast){

            int count = 0 ;
            while(fast -> next != slow){
                count++ ; fast= fast-> next ;
            }return count+1 ;
        }
        else{

            while(slow -> next != fast -> next){
                slow = slow -> next ; fast = fast -> next ;
            }
        }

        // slow -> next is the first node of the loop and fast is at the last node of the loop --> using this we can simply count the length of the loop
        int count =0 ;
        while(slow  != fast){
            count++ ; slow= slow -> next ;
        }
        
        
        return count ;
}