#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// Leetcode verion of Burning the Tree

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
    int amountOfTime(TreeNode *root, int start) {
        TreeNode* key=NULL;
        unordered_map<TreeNode* , TreeNode*> mp ;
        // <child, parent>
        queue<TreeNode*> helper; helper.push(root) ;
        mp[root]= NULL ;

        while(!helper.empty()) {
            TreeNode* curr = helper.front() ; helper.pop() ;
            if(!key and curr -> val == start) {key = curr ;}
            if(curr -> left) {
                mp[curr -> left] = curr ;
                helper.push(curr -> left) ;
            }
            if(curr ->right) {
                mp[curr ->right] = curr ;
                helper.push(curr ->right);
            }
        }

        unordered_set<TreeNode*> isVisited ;
        queue<TreeNode*> q ; q.push(key) ; isVisited.insert(key) ;
        int cnt (-1) ;
        while(!q.empty()) {
            cnt++ ;
            int size = q.size() ;
            for(int i =0 ;i < size; i++) {
                TreeNode* curr = q.front(); q.pop() ;
                if(curr -> left and !isVisited.count(curr->left)) {
                    q.push(curr->left) ;
                    isVisited.insert(curr->left) ;
                }
                if(curr->right and !isVisited.count(curr->right)){
                    q.push(curr->right) ;
                    isVisited.insert(curr->right);
                }
                if(mp[curr] and !isVisited.count(mp[curr])) {
                    q.push(mp[curr]) ;
                    isVisited.insert(mp[curr]) ;
                }
            }
        }
        return cnt ;
    }
};