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

// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// approach : use inorder traversal (which gives us sorted order of the nodes of the tree) -> return the kth node according to the counter variable

// for kth largest element -> return (n-k+1)th smallest element of the bst

class Solution {
public:
    int KthSmallestElement(Node *root, int K) {
        // use iterative inorder traversal that would be easy
        
        int cnt=0; stack<Node*> st; 
        while(root or !st.empty()) {

            if(root){
                st.push(root); root = root -> left; 
            }
            else{
                Node* temp = st.top() ; st.pop() ;
                if(++cnt ==K) {
                    return temp -> data ;
                }
                root = temp -> right ;
            }
        }
        return -1 ;

    }
};