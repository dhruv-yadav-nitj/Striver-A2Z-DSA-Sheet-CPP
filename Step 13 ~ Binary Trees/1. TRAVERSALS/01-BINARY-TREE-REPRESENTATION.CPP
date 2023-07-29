#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/create-binary-tree_8360671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// Problem : Convert the given Array into a Complete Binary Tree (all levels are filled from left to right)

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(vector<int>&arr){
    // Write your code here.
    
    Node* root = new Node (arr[0]) ;

    queue <Node*> q ; q.push(root) ; int i =1, n= arr.size() ;
    while(!q.empty() and i < n) {
        auto it = q.front() ; q.pop() ;

        it -> left = new Node (arr[i++]) ;
        q.push(it -> left) ;

        if(i < n) {
            it -> right = new Node (arr[i++]) ;
            q.push(it -> right) ;
        }
    }
    return root ;

}