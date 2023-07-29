#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

// simple recursion based problem

struct Node {
    int data; struct Node *left; struct Node *right;

    Node(int x) {
        data = x; left = right = NULL;
    }
};

class Solution {
public:
    int s (Node* node, int &maxi) {
        if(!node) {return 0;}

        int lefti = max(0, s(node -> left, maxi)) , righti = max(0, s(node -> right , maxi)) ;
        maxi = max(maxi, lefti + righti + node -> data);
        return max(node -> data + lefti, node -> data + righti) ;
    }

    int findMaxSum(Node *root) {
        // Your code goes here

        int maxi = INT_MIN ; int temp = s(root, maxi) ;
        return maxi ;
    }
};