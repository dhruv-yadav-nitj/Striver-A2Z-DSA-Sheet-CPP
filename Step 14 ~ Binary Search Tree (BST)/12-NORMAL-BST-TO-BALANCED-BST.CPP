#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder (TreeNode<int>*root, vector<int>&in) {

    TreeNode<int>*curr = root ; stack<TreeNode<int>*> st ;
    while(curr or !st.empty()) {

        if(curr) {
            st.push(curr) ; curr = curr->left ;
        }
        else{
            in.push_back(st.top() -> data); curr = st.top() ->right ; st.pop() ;
        }
    }
}

TreeNode<int>* construct (vector<int>in , int l, int r) {

    if(l > r) {
        return NULL ;
    }

    int mid = l + (r - l)/2 ;
    TreeNode<int>*curr = new TreeNode<int> (in[mid]) ;
    curr ->left = construct(in , l, mid-1) ; curr ->right = construct(in, mid +1,r) ;
    return curr ;
}

TreeNode<int> *balancedBst(TreeNode<int> *root) {

    vector<int>in; inorder(root, in) ;

    // approach : find the inorder of the given bst -> construct a new bst using this inorder and simple recursion, utilising the fact that inorder is sorted traversal of bst
    
    return construct(in, 0, in.size()-1) ;
}