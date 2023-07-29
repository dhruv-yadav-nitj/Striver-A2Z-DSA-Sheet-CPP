#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data; Node *left; Node *right;

    Node(int val) {
        data = val; left = right = NULL;
    }
};

// Recursive Approach
class Solution {
public:

    void inorderT (struct Node* root, vector<int>&inorder) {

        if(root == NULL) {return ;}

        // left -> root -> right
        inorderT (root -> left , inorder) ;

        inorder.push_back(root -> data) ;

        inorderT (root -> right , inorder) ;
    }

    void preorderT (struct Node* root, vector<int>&inorder) {

        if(root == NULL) {return ;}

        // root -> left -> right

        inorder.push_back(root -> data) ;

        inorderT (root -> left , inorder) ; inorderT(root -> right, inorder) ;
    }

    void postorderT (struct Node* root, vector<int>&postorder) {

        if(root == NULL) {return ;}

        // left -> right -> root 

        postorderT (root -> left , postorder) ;
        
        postorderT (root -> right , postorder) ;

        postorder.push_back(root -> data) ;
    }

    vector<vector<int>> dfs (struct Node* root) {

        vector<vector<int>> ans ;
        vector<int> inorder, preorder, postorder ;

        inorderT (root, inorder) ; preorderT (root, preorder) ; postorderT (root, postorder) ;

        ans.push_back(preorder) ; ans.push_back(inorder) ; ans.push_back(postorder) ;

        return ans ;
    }
    
};

// hint : any recursive solution can be converted to iterative solution using stack 

// iterative approach
class Solution {
public:

    // preorder traversal using stack
    vector<int> preorder (struct Node* root) {

        vector<int> ans ; if(!root) {return ans ;}

        stack<Node*> st ; st.push(root) ;

        // preorder is root -> left -> right but while using stack we need to first push right and then left because then only left would be at the top and would be considered before right node

        while(!st.empty()) {
            auto it = st.top() ; st.pop() ;

            ans.push_back(it -> data) ;

            if(it -> right) {
                st.push(it -> right) ;
            }

            if(it -> left) {
                st.push(it -> left) ;
            }
        }

        return ans ;
    }

    // postorder traversal using two stacks
    vector<int> postorder (struct Node* root) {

        vector<int> ans ; if(!root) {return ans ;}

        stack<Node*> s1 , s2 ; s1.push(root); 

        while(!s1.empty()) {

            auto it = s1.top() ; s1.pop() ;
            s2.push(it) ;

            if(it -> left) {
                s1.push(it -> left) ;
            }
            if(it -> right) {
                s1.push(it -> right) ;
            }
        }

        while(!s2.empty()) {ans.push_back(s2.top() -> data) ; s2.pop() ;}

        return ans ;
    }

    // postorder traversal using single stack
    vector<int> postorder (struct Node* root) {
        // code here

        vector<int> ans; if(!root) {return ans ;}

        stack<Node*> st ; Node* curr = root ;

        while(curr or !st.empty()) {

            if(curr) {
                st.push(curr) ; curr = curr -> left ;
            }
            else{

                Node* temp = st.top() -> right ;

                if(temp) {

                    // if temp != NULL -> just move curr  to temp and move on
                    curr = temp ;
                }
                else{

                    temp = st.top() ; // mtlab we are standing at some node jiska left aur right dono hi NULL hain -> insert this into the ans
                    ans.push_back(temp -> data) ; st.pop() ;

                    while(!st.empty() and temp == st.top()-> right) {

                        temp = st.top() ; st.pop() ;
                        ans.push_back(temp -> data) ;
                    }
                }
            }
        }

        return ans ;
    }    
};

// iterative inorder traversal

// https://leetcode.com/problems/binary-tree-inorder-traversal/

struct TreeNode {
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
    vector<int> ans ; TreeNode* curr = root ; stack<TreeNode*> st ;
    while(curr or !st.empty()) {
        if(curr) {
            st.push(curr) ; curr = curr -> left ;
        }
        else{
            TreeNode* temp = st.top() ; st.pop() ;
            ans.push_back(temp ->val) ; curr = temp -> right ;
        }
    }
    return ans ;
    }
};