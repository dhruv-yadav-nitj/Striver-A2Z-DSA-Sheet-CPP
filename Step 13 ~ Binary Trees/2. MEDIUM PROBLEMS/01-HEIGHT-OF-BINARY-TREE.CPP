#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

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

// normal recursion based problem

class Solution {
public:
    int h (struct Node* node) {
        // base condition
        if(!node) {return 0;}

        return 1 + max(h(node -> left), h(node -> right)) ;

    }
    int height(struct Node *node) {
        // code here
        return h (node) ;
    }
};