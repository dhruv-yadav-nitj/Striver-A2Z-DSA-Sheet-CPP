#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

struct Node {
    int data; struct Node *left; struct Node *right;

    Node(int x) {
        data = x; left = right = NULL;
    }
};

class Solution {
public:
    vector<int> zigZagTraversal(Node *root) {
        // Code here

        vector<int> ans ;
        queue<Node*> q ; q.push(root) ; int level = 0 ;

        while(!q.empty()) {
            int size= q.size() ;
            vector<int> temp ;
            for(int i =0 ; i < size ; i++) {
                auto it = q.front() ; q.pop() ;
                temp.push_back(it-> data) ;
                if(it -> left) {q.push(it->left) ;}
                if(it -> right) {q.push(it -> right) ;}
            }

            if(level%2==0) {
                // means even level (left -> right)
                ans.insert(ans.end() , temp.begin() , temp.end()) ;
            }
            else{
                reverse(temp.begin() , temp.end()) ;
                ans.insert(ans.end(), temp.begin() , temp.end()) ;
            }
            ++level;
        }
        return ans ;

    }
};