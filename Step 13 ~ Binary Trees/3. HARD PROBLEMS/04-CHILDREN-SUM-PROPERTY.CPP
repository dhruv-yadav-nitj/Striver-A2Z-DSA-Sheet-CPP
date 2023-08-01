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

// https://practice.geeksforgeeks.org/problems/children-sum-parent/1

// In this problem we have to just check if the given tree follows Children Sum Property or not
// fuddu recursion problem

class Solution {
public:
    
    bool isLeaf (Node* node) {
        return (!node-> left and !node-> right) ;
    }
    
    bool check (Node* node) {

        if(!node or isLeaf(node)){return true ;}

        int left(0) , right(0) ;
        if(node -> left) {left = node -> left ->data ;}
        if(node -> right) {right = node -> right -> data ;}

        if(node -> data != left + right) {return false ;}

        else {
            return (check(node -> left) and check(node -> right)) ;
        }

    }

    int isSumProperty(Node *root) {

        return check(root) ;
        
    }
};