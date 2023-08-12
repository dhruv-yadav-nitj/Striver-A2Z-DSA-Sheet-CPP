#include <bits/stdc++.h>
using namespace std;

// approach #1 : find inorder (or any traversal) -> sort the traversal (to get the correct traversal of the bst) -> re-traverse the bst in the same manner as inorder -> correct the value of nodes that dont match with the sorted inorder -> Time ~ O(N) + O(NlogN) + O(N)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// approach #2 : instead of storing the whole inorder traversal we would just store the two pointers' nodes where we the tree have violated the sorted order -> how we would do that ? -> while traversing -> if the curr node is not greater than the prev node -> mark this node

// LEETCODE Version

class Solution {
public:
    TreeNode *prev, *first, *mid, *last ;
    void inorder (TreeNode* curr) {

        // base condition
        if(!curr){return ;}

        // go to left
        inorder(curr -> left) ;

        // when returns compare curr with prev
        if(prev and curr->val < prev->val) {
            if(!first){
                first = prev ; mid = curr ;
            }
            else{
                last = curr ;
            }
        }

        prev= curr ;
        inorder(curr ->right) ;

    }
    void recoverTree(TreeNode *root) {

        prev = first = mid = last = NULL ; // initialise the pointers

        inorder(root) ;

        if(first and last) {
            swap(first -> val, last -> val) ;
        }
        else{
            swap(first -> val, mid ->val) ;
        }
    }
};

// GfG Version
// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    Node* prev, *first, *mid, *last ;
public:
    void inorder (struct Node* curr) {

        if(!curr){return  ;}

        inorder (curr -> left) ;

        if(prev and curr -> data < prev -> data) {

            if(!first) {
                first = prev;  mid = curr ;
            }
            else{
                last = curr ;
            }
        }

        prev = curr ; inorder (curr ->right) ;

    }
    void correctBST(struct Node *root) {
        prev = first = mid = last = NULL ;

        inorder(root) ;
        if(first and last) {
            swap(first -> data , last -> data) ;
        }
        else{
            swap(first -> data , mid -> data) ;
        }
        
    }
};