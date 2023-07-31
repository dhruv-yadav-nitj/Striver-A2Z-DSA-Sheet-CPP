#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; struct Node* left; struct Node* right;
    
    Node(int x) {
        data = x; left = right = NULL;
    }
};

// fuddu ques

class Solution {
public:
    bool check (Node* node1, Node* node2) {

        if(!node1 and !node2) {return true ;}

        if((!node1 and node2) or (node1 and !node2)){return false;}

        if(node1 -> data != node2 -> data) {return false;}

        if(check(node1-> left, node2-> right)) {
            return check(node1 -> right, node2 -> left) ;
        }
        else{return false;}
    }

    bool isSymmetric(struct Node *root) {
    
        return check(root,root) ;

    }
};