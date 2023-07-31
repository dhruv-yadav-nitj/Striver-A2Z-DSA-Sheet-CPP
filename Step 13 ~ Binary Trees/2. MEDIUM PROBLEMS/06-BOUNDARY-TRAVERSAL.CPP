#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// very direct approach :
/* 

first add all the left sided nodes, which are not lead nodes

then add all the leaf nodes using preorder

then add all the right sided nodes which are not leaf nodes

*/

struct Node {
    int data; struct Node *left; struct Node *right;

    Node(int x) {
        data = x; left = right = NULL;
    }
};

class Solution {
public:

    bool isLeaf (Node* node) {

        return (!(node-> left) and !(node -> right)) ;

    }

    void addLeft (Node* root, vector<int>&ans){

        if(!root){return ;}
        
        if(!isLeaf(root)) {
            ans.push_back(root -> data) ;

            if(root -> left) {addLeft(root -> left, ans) ;}
            else{
                addLeft (root -> right, ans) ;
            }
        }
    }

    void addLeaf (Node* node, vector<int>&ans) {

        if(node == NULL) {return ;}

        if(isLeaf(node)) {ans.push_back(node -> data) ;}

        addLeaf(node -> left, ans) ; addLeaf (node -> right, ans) ;
    }

    void addRight (Node* node, vector<int>&temp) {

        if(node== NULL) {return ;}

        if(!isLeaf(node)) {temp.push_back(node -> data) ;}

        if(node -> right) {addRight(node -> right, temp) ;} else{addRight(node-> left, temp) ;}
    }

    vector<int> boundary(Node *root) {
        
        vector<int> ans,temp ; if(!root) {return ans ;}

        if(isLeaf(root)) {return {root -> data} ;}

        ans.push_back(root -> data) ;

        addLeft(root -> left, ans) ; addLeaf(root, ans) ; addRight(root -> right, temp) ;

        reverse(temp.begin(), temp.end()) ; ans.insert(ans.end(), temp.begin(), temp.end()) ;

        return ans ;

    }
};