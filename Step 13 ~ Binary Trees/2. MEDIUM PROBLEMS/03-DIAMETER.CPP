#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

struct Node {
    int data; struct Node *left; struct Node *right;

    Node(int x) {
        data = x; left = right = NULL;
    }
};

// Diameter -> longest distance b/w any two nodes of the tree (it may or may not path through root)

// intuition : height of binary tree
class Solution {
public:
    int h (Node* root, int &ans) {

        if(!root){return 0 ;}

        int l = h (root -> left, ans) , r = h (root ->right, ans) ;
        ans = max(ans , 1 + l+ r) ;

        return 1 + max(l, r);

    }
    int diameter(Node *root) {
        int ans = 0 ;
        h (root, ans); return ans ;
    }
};