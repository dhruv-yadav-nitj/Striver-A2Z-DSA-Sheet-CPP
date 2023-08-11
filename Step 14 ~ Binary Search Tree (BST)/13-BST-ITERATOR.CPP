#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Implementation is very simple -> we just need to understand what is the problem asking for.

class BSTIterator {
public:

    stack<TreeNode*> st ;
    // custom-made function
    void pushAll (TreeNode* curr) {
        while(curr) {
            st.push(curr) ; curr =curr -> left ;
        }
    }
    
    BSTIterator(TreeNode *root) {
        pushAll (root) ;
    }

    // return the next smallest element
    int next() {
        TreeNode* curr = st.top() ; st.pop() ;
        pushAll(curr -> right) ;
        return curr -> val ;     
    }

    // return if we have another smallest element
    bool hasNext() {
        return (!st.empty()) ;
    }
};