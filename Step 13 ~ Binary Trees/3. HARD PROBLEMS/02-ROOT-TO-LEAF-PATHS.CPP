#include <bits/stdc++.h>
using namespace std;

// FUDDU QUES -> just apply normal recursion

struct Node
{
    int data; Node *left; Node *right;
};

bool isLeaf (Node* node) {

    return  (node-> left == NULL and node -> right == NULL) ;

}

void traversal (Node* node, vector<int>temp, vector<vector<int>>&ans) {

    if(!node) {return ;}

    if(isLeaf(node)) {
        temp.push_back(node-> data); ans.push_back(temp) ;
        return ;
    }

    temp.push_back(node -> data) ;

    if(node -> left) {
        traversal(node -> left , temp , ans) ;
    }
    if(node-> right) {
        traversal(node-> right, temp, ans) ;
    }

    temp.pop_back() ;

}

vector<vector<int>> Paths(Node *root) {

    vector<vector<int>> ans ; 

    traversal(root, {} , ans) ; return ans ;

}