#include <bits/stdc++.h>
using namespace std;

// https://rb.gy/cg1cb

bool check(Node *curr, int x)
{

    if (curr == NULL)
    {
        return false;
    }

    if (curr->data == x)
    {
        return true;
    }

    if (curr->data > x)
    {
        return check(curr->left, x);
    }
    else
    {
        return check(curr->right, x);
    }
}
bool search(Node *root, int x)
{
    // Your code here
    return check(root, x);
}
