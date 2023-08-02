#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/burning-tree/1

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

// Follow-up question for previous Problem (same approach)

class Solution {
public:
    int minTime(Node *root, int target) {
        
        unordered_map<Node*, Node*> parent ;
        parent[root] = NULL ;

        queue<Node*> q ; q.push(root) ; parent[root]=NULL ;

        Node* node = NULL ;

        while(!q.empty()) {

            auto it = q.front() ; q.pop() ;
            
            if(it->data == target) {node = it ;}

            if(it -> left) {
                q.push(it->left) ;
                parent[it->left] = it ;
            }
            if(it -> right){
                q.push(it->right) ;
                parent[it->right]= it ;
            }
        }

        int time(0) ; 

        queue<pair<Node*,int>> qu ;
        qu.push({node, 0}) ; unordered_map<Node*, bool> isVisited;
        isVisited[node] = true ;

        while(!qu.empty()) {

            auto it = qu.front() ; qu.pop() ;
            Node* curr= it.first ; int t = it.second ;

            time = max(time, t) ;

            if(curr -> left and !isVisited[curr-> left]) {

                qu.push({curr->left, t +1}) ; isVisited[curr->left] = true ;

            }

            if(curr -> right and !isVisited[curr-> right]) {

                qu.push({curr->right, t +1}) ; isVisited[curr->right] = true ;

            }

            if(parent[curr] and !isVisited[parent[curr]]) {
                qu.push({parent[curr], t +1}) ; isVisited[parent[curr]] = true ;
            }

        }

        return time;

    }
};