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

// the approach is very clear -> we just provided some range to a particular node and checked if the node->val lies in that range or not
// if we would move from one node towards its left -> then its upperlimit would change and if we would move towards its right then its lower limit would change

class Solution {
public:
    bool checkBST (Node* curr, int l, int r)  {

        if(!curr){return true ;}

        if(curr -> data > l and curr -> data < r) {

            return checkBST(curr -> left, l, curr -> data) and checkBST(curr -> right, curr->data , r) ;
        }
        else{
            return false ;
        }

    }
    bool isBST(Node *root) {
        return checkBST(root, INT_MIN, INT_MAX) ;
    }
};