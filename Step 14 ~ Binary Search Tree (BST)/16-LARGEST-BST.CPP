#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// [HARD]
// https://practice.geeksforgeeks.org/problems/largest-bst/1
// Explanation : https://youtu.be/X0oXMdtUDwo
class NodeValue {
public:
    int maxNode , minNode, maxSize ;
    NodeValue (int minNode, int maxNode, int size) {
        this -> maxNode = maxNode ;
        this -> minNode = minNode ;
        this -> maxSize = size ;
    }
};

class Solution {
public:

    NodeValue helper (Node* root) {
        // empty subtree -> size = 0
        if(!root){return NodeValue(INT_MAX, INT_MIN, 0) ;}

        auto left = helper (root -> left) ;
        auto right = helper(root ->right) ;

        if(left.maxNode < root -> data and right.minNode > root -> data) {
            return NodeValue(min(root -> data, left.minNode), max(root -> data, right.maxNode), left.maxSize + right.maxSize +1) ;
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize)) ;

    }

    int largestBst(Node *root) {
        return helper(root).maxSize ;
    }
};