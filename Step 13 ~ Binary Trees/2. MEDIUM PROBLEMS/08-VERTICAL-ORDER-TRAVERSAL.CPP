#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> verticalOrder(Node *root) {

        if(!root){return {};}

        queue<pair<Node*, pair<int,int>>> q ; // <node , <vertical, level>>
        q.push({root, {0, 0}}) ;

        map<int, map<int, vector<int>>> mp ; // <vertical level, horizontal level, nodes>

        // we have used vector<int> to store the nodes which appear in same vertical and horizontal level -> bcz we were asked to return the nodes in the order in which they appear while traversing level order and not in sorted manner -> if it was asked to return the nodes in sorted manner then we would have used set

        while(!q.empty()) {

            auto it = q.front() ; q.pop() ;

            Node* node = it.first; int v = it.second.first, l = it.second.second ;

            mp[v][l].push_back(node -> data) ;

            if(node -> left){
                q.push({node -> left, {v - 1, l +1}}) ;
            }
            if(node -> right) {
                q.push({node -> right, {v+1, l+1}}) ;
            }
        }

        vector<int> ans ; 

        for(auto it : mp) {

            for(auto x : it.second) {

                for(auto y : x.second) {
                    ans.push_back(y) ;
                }
            }
        }

        return ans ;

    }
};