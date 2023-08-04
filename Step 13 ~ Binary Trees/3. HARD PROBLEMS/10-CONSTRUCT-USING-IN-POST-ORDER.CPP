#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// approach similar to prev problem
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

    TreeNode* construct (vector<int>&in, vector<int>&post, int inS, int inE, int postS, int postE, unordered_map<int,int>&mp) {

        if(inS > inE or postS > postE) {
            return NULL ;
        }

        TreeNode* root = new TreeNode(post[postE]) ;
        int index = mp[root -> val] ; int nLeft = index - inS ;

        root -> left = construct (in, post, inS, index -1, postS, postS + nLeft -1, mp) ;

        root -> right = construct(in, post, index+1, inE, postS + nLeft, postE -1 , mp) ;

        return root ;

    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

        int n = inorder.size() ; 
        unordered_map<int,int>mp ;
        for(int i =0 ; i < n ; i++) {
            mp[inorder[i]] = i ;
        }

        return construct(inorder, postorder, 0, n, 0, n-1, mp) ;

    }
};