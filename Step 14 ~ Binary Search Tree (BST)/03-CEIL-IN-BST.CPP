#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

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

int findCeil(Node *root, int input)
{
    if (root == NULL)
    {
        return -1;
    }

    int ans = -1 ;

    while(root) {

        if(root -> data >= input) {

            ans = root -> data ;
            root = root -> left ;
        }
        else{
            root = root -> right ;
        }
    }
    return ans ;
}