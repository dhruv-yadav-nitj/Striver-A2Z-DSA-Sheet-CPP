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

// intuition -> based on height of binary tree and basic recursion

class Solution {
public:
    int h (Node* node, int&ans) {
        if(node == NULL) {return 0 ;}

        int lefti = h (node -> left , ans) , righti = h (node-> right , ans) ;
        ans = max(ans, lefti + righti + 1) ;
        return 1 + max(lefti, righti) ;
    }
    int diameter(Node *root) {
        // Your code here

        int ans =1 ;
        h (root, ans) ; return ans ;

    }
};