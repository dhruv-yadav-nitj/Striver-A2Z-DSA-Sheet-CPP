#include <bits/stdc++.h>
using namespace std;

// [PROBLEM LINK]

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

void construct (Node* node) {

    if(!node) {return ;}
    int left= 0, right=0; 
    if(node -> left){left = node -> left -> data ;}
    if(node -> right) {right = node->right->data ;}

    if(node -> data > left +right) {
        if(node -> left) {node->left->data = node->data ;}
        else if(node->right) {node->right->data = node->data ;}
    }

    if(node -> left) {construct(node->left) ;}
    if(node -> right) {construct(node->right) ;}

    int childSum =0 ;
    if(node -> left) {childSum += node -> left -> data ;}
    if(node -> right) {childSum += node -> right -> data ;}

    if(node -> left or node -> right) {
        node -> data = childSum ;
    }

}

Node* childrenSumProperty (Node*root) {

    construct(root) ; return root ;

}