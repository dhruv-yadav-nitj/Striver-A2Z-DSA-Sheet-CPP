#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-complete-tree-nodes/description/

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

// approach #1 : count all the nodes using any traversal
class Solution
{
public:
    void dfs(Node *node, int &cnt)
    {
        if (!node)
        {
            return;
        }
        cnt += 1;
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    }
    int countNodes(Node *root)
    {
        // Write your code here
        int cnt(0);
        dfs(root, cnt);
        return cnt;
    }
};

// approach #2 : Time ~ O(n)
class Solution {
public:

    int leftHeight (Node* node){

        int cnt(0) ;
        while(node) {
            cnt++ ; node = node->left ;
        }
        return cnt ;
    }

    int rightHeight (Node* node) {
        int cnt(0) ;
        while(node) {
            cnt++ ; node = node->right ;
        }
        return cnt;
    }

    int count (Node* node) {

        int l = leftHeight(node), r = rightHeight(node) ;
        if(l==r){return pow(2, l) -1 ;}

        int left = count(node-> left) , right = count(node->right);

        return 1 + left + right ;

    }

    int countNodes(Node *root) {

        return count(root) ;

    }
};
