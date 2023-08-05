#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        Node* curr = root ;
        while(curr and curr->right){
            curr= curr->right ;
        }
        return curr-> data ;
    }
    int findMin(Node *root)
    {
        //code here
        Node* curr = root ;
        while(curr and curr->left) {
            curr= curr -> left ;
        }
        return curr -> data ;
    }
};