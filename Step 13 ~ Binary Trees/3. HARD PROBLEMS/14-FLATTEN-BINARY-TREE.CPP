#include <bits/stdc++.h>
using namespace std;

// Problem Link:
// https://rb.gy/qgcjx

struct Node
{
    int data;
    struct Node *left, *right;
};

// recursive solution (most easy to understand)

// do some dry run your self

class Solution
{
public:
    Node* prev = NULL ;
    void flatten(Node *root) {

        if(!root){return ;}

        flatten(root ->right) ; flatten(root ->left) ;

        root ->right = prev ; root -> left = NULL ;
        prev = root ;
    }
};