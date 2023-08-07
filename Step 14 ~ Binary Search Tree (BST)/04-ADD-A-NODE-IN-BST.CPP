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

Node *insert(Node *root, int Key)
{
    // Your code here
    int key = Key;
    Node *curr = root;
    Node *prev = root;

    while (curr)
    {

        if (key == curr->data)
        {
            return root;
        }
        else if (key < curr->data)
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            prev = curr;
            curr = curr->right;
        }
    }

    if (key < prev->data)
    {
        prev->left = new Node(key);
    }
    else
    {
        prev->right = new Node(key);
    }
    return root;
}
