#include <bits/stdc++.h>
using namespace std;

// Problem Link
// https://rb.gy/xoidp

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {

        vector<int> serialise ; if(root == NULL){return serialise ;}

        queue <Node*> q ; q.push(root);

        while(!q.empty()) {

            auto it = q.front() ; q.pop() ;

            if(it) {
                serialise.push_back(it -> data) ;
            }
            else{
                serialise.push_back(-1) ;
            }

            if(it) {
                q.push(it ->left) ; q.push(it ->right) ;
            }
        }
        return serialise ;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {

        int i =0, n = A.size() ;

        if (n ==0){return NULL ;} // if the serialise vector is empty

        Node* root = new Node(A[i++]) ;

        queue<Node*> q ; q.push(root) ;

        while(!q.empty()) {

            auto it = q.front() ; q.pop() ;

            if(A[i] != -1) {

                it ->left = new Node(A[i++]) ;
                q.push(it -> left) ;
            }
            else{
                it -> left = NULL ;
                i++ ;
            }

            if(A[i] != -1) {
                it ->right = new Node(A[i++]) ;
                q.push(it ->right) ;
            }
            else{
                it -> right = NULL ; i++ ;
            }
        }

        return root ;
        
    }
};