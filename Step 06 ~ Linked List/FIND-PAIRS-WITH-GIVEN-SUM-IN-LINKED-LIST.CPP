#include <bits/stdc++.h>
using namespace std ;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

// Approach : Since we can move in both the directions in a doubly linekd list --> we would be using two pointers --> one from start and other from end --> if left + right < val --> mvoe left forward and if left + right > val --> move right backward

class Solution{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        // code here

        Node* left = head , *right = head;
        while(right -> next != NULL){right= right-> next ;}

        // since we can move both left and right in the doubly linked list --> so this approach would be the most efficient one
        vector<pair<int, int>> ans ;
        while(left != NULL and right != NULL and left != right){
            if(left -> data + right -> data < target){
                left = left -> next ; 
            }
            else if(left -> data + right -> data > target){
                right = right -> prev ;
            }
            else{
                ans.push_back({left -> data , right -> data}) ;
                left= left -> next ;
            }
        }

        return ans ;

    }
};