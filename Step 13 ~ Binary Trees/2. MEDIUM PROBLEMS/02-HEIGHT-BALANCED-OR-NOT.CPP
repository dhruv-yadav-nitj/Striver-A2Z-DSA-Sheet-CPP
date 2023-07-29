#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

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

// no special intution but normal recursion based problem

class Solution {
public:
    int h (Node* root) {

        if(root == NULL) {return 0 ;}

        int lefti = h (root -> left) ;
        if(lefti == -1) {return -1 ;}

        int righti = h (root -> right) ;
        if(righti == -1){return -1 ;}

        if(abs(lefti - righti) > 1) {return -1 ;}

        return max(lefti, righti) +1 ;

    }
    bool isBalanced(Node *root) {
        //  Your Code here
        return (h(root) != -1) ;
    }
};