#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// approach #1: find the inorder and then simply apply two sum problem approach

// approach #2 : using bst iterator

// BST iterator
class BSTIterator {
public:

    stack<TreeNode*> st ; bool reverse ;

    BSTIterator(TreeNode *root, bool rev) {
        reverse = rev ; // update the reverse according to the instruction
        pushAll (root) ;
    }

    int next() {
        TreeNode* curr = st.top() ; st.pop() ;

        if(reverse) {
            pushAll(curr -> left) ;
        }
        else{
            pushAll(curr ->right) ;
        }
        
        return curr -> val ;
    }

    // custom-made function
    void pushAll (TreeNode* curr) {
        while(curr) {
            st.push(curr) ;
            // move in the direction according to the given instruction directed by reverse
            if(reverse){curr = curr -> right ;} else{curr =curr -> left ;}
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if(!root) {
            return false ;
        }

        BSTIterator left(root, false) ; BSTIterator right(root, true);

        int i = left.next() , j = right.next() ;

        while(i < j) {

            int sum = i + j ;
            if(sum == k) {return true ;}
            else if(sum < k) {i = left.next() ;}
            else{
                j = right.next() ;
            }
        }
        return false;
    }
};