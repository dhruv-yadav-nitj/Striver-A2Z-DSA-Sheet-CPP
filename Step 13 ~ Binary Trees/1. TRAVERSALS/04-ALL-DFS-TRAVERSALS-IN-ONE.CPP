#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> traversals (TreeNode*root) {
        if(!root) {return {{}} ;} // if tree is empty return empty vector

        vector<int> pre, in, post ; // separate vectors for preorder, inorder and postorder traversal

        stack<pair<TreeNode*, int>> st ; st.push({root, 1}) ;

        while(!st.empty()) {

            auto it = st.top() ; st.pop() ;
            TreeNode* curr = it.first ; int num= it.second ;

            if(num ==1) {
                pre.push_back(curr -> val) ;
                st.push({curr, num+1}) ;

                if(curr -> left) {st.push({curr -> left, 1}) ;}

            }
            else if(num == 2) {
                in.push_back(curr -> val) ;
                st.push({curr, num+1}) ;

                if(curr -> right) {st.push({curr -> right, 1});}
                
            }
            else if(num == 3) {
                post.push_back(curr -> val) ;
            }
        }

        return {pre, in, post} ;

    }

};