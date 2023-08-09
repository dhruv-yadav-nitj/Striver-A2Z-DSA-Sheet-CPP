#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* construct (vector<int>&preorder, vector<int>&inorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int,int>&mp) {

        if(inStart > inEnd or preStart > preEnd) {
            return NULL ;
        }

        TreeNode* root = new TreeNode(preorder[preStart]) ;
        int index = mp[root->val] ; // index of current root in inorder

        int nLeft = index - inStart ;

        root->left = construct (preorder, inorder, inStart, index -1, preStart +1, preStart + nLeft, mp) ;
        root->right = construct(preorder, inorder, index+1, inEnd, preStart+nLeft+1, preEnd, mp) ;

        return root ;

    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        // create a hashtable to optimise the searching of current root node in inorder traversal
        int n = inorder.size() ; unordered_map<int,int> mp ;
        for(int i =0 ; i < n ; i++) {
            mp[inorder[i]] = i ;
        }

        return construct(preorder, inorder, 0, n-1, 0, n-1, mp) ;

    }
};