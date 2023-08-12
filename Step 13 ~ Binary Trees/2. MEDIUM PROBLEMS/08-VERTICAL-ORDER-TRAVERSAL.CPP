#include <bits/stdc++.h>
using namespace std;

// Leetcode Version
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {

        if(!root) {return {{}} ;}

        vector<vector<int>> ans ;

        queue<pair<TreeNode*, pair<int,int>>> q ; q.push({root, {0, 0}}) ;
        map <int , map<int, multiset<int>>> mp ;
        while(!q.empty()) {

            auto it = q.front() ;
            TreeNode* curr = it.first ; int ver = it.second.first, lev = it.second.second ;
            
            mp[ver][lev].insert(curr -> val);

            if(curr -> left) {
                q.push({curr -> left, {ver-1, lev+1}}) ;
            }
            if(curr ->right) {
                q.push({curr ->right, {ver+1, lev+1}}) ;
            }
        }

        for(auto x : mp) {
            vector<int> temp ;
            for(auto y : x.second) {
                for(auto z : y.second) {
                    temp.push_back(z) ;
                }
            }
            ans.push_back(temp) ;
        }
        return ans ;

    }
};

// GFG Version

// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
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

class Solution
{
public:
    vector<int> verticalOrder(Node *root)
    {

        if (!root)
        {
            return {};
        }

        queue<pair<Node *, pair<int, int>>> q; // <node , <vertical, level>>
        q.push({root, {0, 0}});

        map<int, map<int, vector<int>>> mp; // <vertical level, horizontal level, nodes>

        // we have used vector<int> to store the nodes which appear in same vertical and horizontal level -> bcz we were asked to return the nodes in the order in which they appear while traversing level order and not in sorted manner -> if it was asked to return the nodes in sorted manner then we would have used set

        while (!q.empty())
        {

            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int v = it.second.first, l = it.second.second;

            mp[v][l].push_back(node->data);

            if (node->left)
            {
                q.push({node->left, {v - 1, l + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {v + 1, l + 1}});
            }
        }

        vector<int> ans;

        for (auto it : mp)
        {

            for (auto x : it.second)
            {

                for (auto y : x.second)
                {
                    ans.push_back(y);
                }
            }
        }

        return ans;
    }
};