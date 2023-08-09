#include <bits/stdc++.h>
using namespace std;

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

// just added some BST property to the finding LCA in binary tree -> else all the approach is same
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

class Solution
{
public:
    Node *LCA(Node *root, int n1, int n2) {
        // base condition
        if(!root or root -> data == n1 or root -> data == n2) {
            return root ;
        }

        Node* left(NULL), *right(NULL) ;

        if(root -> data > n1 and root -> data > n2){
            return left = LCA(root -> left, n1, n2) ;
        }
        else if(root -> data < n1 and root -> data < n2) {
            return right = LCA(root -> right, n1, n2) ;
        }
        else{
            left= LCA(root -> left, n1, n2) ;
            right= LCA(root -> right, n1, n2) ;
        }

        if(!left){
            return right ;
        }
        else if(!right) {return left ;}
        else{
            return root ;
        }
        
    }
};