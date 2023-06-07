#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;struct Node *next;Node(int x) {
        data = x;next = NULL;
    }

};

// approach #1 : using extra space --> copy all the elements of the LL into some array --> and check if the array is palindrome or not --> Time ~ O(n + n/2) and Space ~ O(n)


// approach #2 : find the mid element of LL --> reverse the second half of the LL and compare it with first half --> Time ~ O(n + n/2) ; Space ~ O(1)
class Solution{
public:

    Node* reverse (Node* head){

        if(head == NULL or head -> next== NULL){
            return head ;
        }

        Node* prev = NULL , *curr= head ;
        while(curr != NULL){

            Node* temp = curr -> next ;
            curr -> next = prev ; 
            prev = curr; curr = temp;
        }

        return prev ;
    }

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        //Your code here

        // empty or single element linked list is always a palindrome
        if(head == NULL or head -> next == NULL){
            return true ;
        }

        // finding the mid element
        Node* slow= head , *fast= head ;

        // slightly modified according to the need of the ques
        while(fast -> next != NULL and fast -> next -> next != NULL){

            slow = slow -> next; fast = fast -> next -> next ;

        }

        // reverse all the nodes after mid (or slow here)
        slow -> next = reverse(slow -> next) ;

        Node* head1 = head , *head2 = slow -> next ;
        while(head2 != NULL){

            if(head1 -> data != head2-> data) {
                return false ;
            }

            head1 = head1-> next ; head2 = head2 -> next ;
        }

        return true ;

    }
};