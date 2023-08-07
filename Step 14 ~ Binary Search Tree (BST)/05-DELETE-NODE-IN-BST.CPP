#include <bits/stdc++.h>
using namespace std;

// [MEDIUM-HARD] PROBLEM

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Explanation : https://www.youtube.com/watch?v=UeRUKRJvPa4

Node* getMini (Node* root) {
    
    while(root) {

        if(root -> left) {
            root = root -> left ;
        }
        else {
            return root ;
        }
    }
}

Node *deleteNode(Node *root, int x) {
    
    // base case 
    if(root == NULL) {return root ;}

    if(root -> data == x) {

        // leaf node
        if(!(root -> left)and !(root -> right)) {
            delete root ;
            return NULL ; 
        }

        // either left or right exist
        
        if(root -> left and !(root -> right)) {
            Node* temp =root -> left ; delete(root) ;
            return temp ;
        }
        else if(root -> right and !(root ->left)) {
            Node* temp = root -> right ; delete(root) ;
            return temp ;
        }

        // both child exist
        else{
            int newVal = getMini (root-> right) ->data ;
            root -> data = newVal ;
            root ->right = deleteNode(root ->right, newVal) ;
            return root ;
        }

    }
    else if (root -> data > x) {
        root -> left = deleteNode(root -> left, x) ;
        return root ;
    }
    else{
        root -> right = deleteNode(root -> right, x) ;
        return root; 
    }
}
