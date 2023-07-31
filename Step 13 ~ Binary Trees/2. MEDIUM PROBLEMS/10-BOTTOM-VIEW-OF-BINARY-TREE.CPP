#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; struct Node* left; struct Node* right;
    
    Node(int x) {
        data = x; left = right = NULL;
    }
};

// completely similar to top view of binary tree

class Solution {
public:
    vector<int> bottomView(Node *root) {
        
        if(!root) {return {} ;}

        map<int, int> mp ; // <vertical level, node value> 

        queue<pair<Node*, int>> q ; q.push({root, 0}) ;

        while(!q.empty()) {

            auto it = q.front() ; q.pop() ;
            Node* node =it.first ; int v = it.second;

            // the only change from top view of binary tree -> for bottom view we will keep updating the node for a vertical level until end
            mp[v] = node -> data ;

            if(node -> left) {q.push({node-> left, v -1}) ;}
            if(node -> right) {q.push({node-> right, v + 1}) ;}

        } 

        vector<int> ans ;

        for(auto it : mp) {ans.push_back(it.second) ;}

        return ans ;

    }
};