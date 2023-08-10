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

// approach #1 : using preorder to first get inorder and then just applying the prev method used to create binary tree
// Time ~ O(nlogn + n)

class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {

        vector<int> inorder = preorder; sort(inorder.begin(), inorder.end()) ;

        unordered_map<int, int> mp ;
        for(int i=0; i < inorder.size() ; i++) {
            mp[inorder[i]]= i;
        }

        int n = inorder.size() ;

        return construct(inorder, preorder, 0, n-1, 0, n-1, mp) ;

    }
    TreeNode* construct (vector<int>&in, vector<int>&pre, int inS, int inE, int preS, int preE, unordered_map<int,int>&mp) {

        // base condition
        if(inS > inE or preS > preE) {return NULL ;}

        TreeNode* curr = new TreeNode(pre[preS]) ;

        int index = mp[curr -> val] ;

        int nLeft = index- inS ;

        curr -> left = construct(in, pre, inS, index -1, preS +1, preS + nLeft, mp) ;

        curr -> right = construct(in, pre, index+1, inE, preS+nLeft+1, preE, mp) ;

        return curr ;

    }
};
// approach #2 : by just using the given preorder traversal (just take the idea from vdo and apply basic recursion)
// https://youtu.be/SXKAD2svfmI
class Solution {
public:
    int index = 0 ;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return construct(preorder, i, INT_MAX) ;
    }

    TreeNode* construct (vector<int>&pre, int&index, int upper) {

        if(index >= pre.size()) {return NULL ;}

        if(pre[index] < upper) {

            // if the current element lies within the range
            TreeNode* curr = new TreeNode(pre[index++]) ;
            curr -> left = construct(pre, index, curr -> val) ;

            curr -> right = construct(pre, index, upper) ;
            return curr ;
        }
        else{
            return NULL ;
        }

    }
};