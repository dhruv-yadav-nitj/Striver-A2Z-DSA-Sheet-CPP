#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        
        if(root == NULL or root -> val == p->val or root -> val == q->val) {
            return root ;
        }

        TreeNode *left, *right ;
        left= lowestCommonAncestor(root -> left, p, q) ;
        right= lowestCommonAncestor(root -> right, p, q) ;

        if(!left) {return right ;}
        if(!right) {return left ;}
        else{
            // means both left and right returned some valid value
            return root ;
        }

    }
};