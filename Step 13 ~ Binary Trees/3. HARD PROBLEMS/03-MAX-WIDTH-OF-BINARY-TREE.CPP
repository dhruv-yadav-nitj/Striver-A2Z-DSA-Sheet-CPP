#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// first I though I should apply the vertical traversal approach (dividing each vertical column using the coordinate system) -> but that approach would be giving error for cases such as 1 3 10 5 7 9 N 5 5 9 2 10 where ans should be 5 but this apporach would give 4
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// correct approach

// LeetCode Version
// https://leetcode.com/problems/maximum-width-of-binary-tree/description/
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root) {

        int cnt =0 ; if(!root){return cnt ;}

        queue <pair<TreeNode*, long long>> q ; q.push({root, 0}) ;
        while(!q.empty()) {

            int size = q.size() ;
            int l , r ; int ref= q.front().second ;
            for(int i=0 ;i < size; i++) {
                TreeNode* curr = q.front().first ; int add = q.front().second-ref ; q.pop() ;
                if(i == 0) {
                    l = add ;
                }
                if(i == size-1) {
                    r = add ;
                }
                if(curr -> left) {
                    q.push({curr -> left, (long long)(add) * 2 + 1}) ;
                }
                if(curr ->right) {
                    q.push({curr->right, (long long)(add) * 2 + 2}) ;
                }
            }
            cnt = max(cnt, (r-l+1));
        }
        return cnt ;

    }
};
// GfG Version (EASY)
class Solution {
public:
    int getMaxWidth(Node *root) {

        if(!root) {return 0 ;}

        int ans = 0; queue<Node*> q ; q.push(root) ;

        while(!q.empty()) {
            
            int size = q.size() ; // size of current level
            ans= max(ans, size) ;
            
            for(int i =0 ; i < size ; i++) {
                
                Node* curr = q.front() ; q.pop() ;
                
                if(curr -> left) {
                    q.push(curr -> left) ;
                }
                if(curr -> right) {
                    q.push(curr -> right) ;
                }
            }
        }

        return ans ;
    }
};