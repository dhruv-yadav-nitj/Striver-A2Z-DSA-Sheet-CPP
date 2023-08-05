#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Approach : the only way to get the intuition is to watch the video and do some dry run your self
// https://youtu.be/80Zug6D1_r4

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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans ;

        TreeNode* curr =root ;

        while(curr) {

            // case 1 : when we dont have any left child of curr node
            if(curr -> left == NULL) {
                ans.push_back (curr->val) ;
                curr = curr -> right ;
            }
            else{

                TreeNode* prev=  curr -> left ;
                // move to the right most node of the left subtree of curr
                while(prev -> right and prev -> right != curr) {
                    prev = prev -> right ;
                }

                // threading
                // move to the left child of curr
                if(prev -> right == NULL) {
                    prev ->right = curr ;
                    curr = curr -> left ;
                }
                else{
                    // unthreading
                    prev -> right = NULL ;

                    ans.push_back(curr -> val) ; curr = curr ->right ;
                }
            }
        }

        return ans ;
        
    }
};