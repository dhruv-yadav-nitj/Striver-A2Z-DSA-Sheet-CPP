#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; struct Node* left; struct Node* right;
    
    Node(int x) {
        data = x; left = right = NULL;
    }
};

vector<int> leftView(Node *root) {
    
    // similar to top and bottom view of binary tree
    // yha pr bs ek difference hain ki wha pr hmlog vertically divide kr lie the aur top view ke lie jo node kisi vertical order level mein phle aa rha tha usko le rhe the for that vertical level aur is problem mein hm log vertically divide na krke horizontally divide krenge aur jo node kisi horizontal level mein phle aa rha hoga usko left view mein consider kr lenge

    // we would travel a horizontal level from left to right and the node which occurs first in a horizontal level would be the left most node in that level

    if(!root) {return {} ;}

    queue<pair<Node*, int>> q ; map<int, int> mp ;

    q.push({root, 0}) ;

    while(!q.empty()) {

        auto it = q.front() ; q.pop() ;

        Node* node = it.first ; int l = it.second ;

        if(!mp.count(l)) {

            mp[l] = node -> data ;
        }

        if(node -> left){q.push({node -> left, l +1}) ;}
        if(node-> right) {q.push({node -> right, l +1}) ;}
    }

    vector<int> ans ; for(auto it : mp) {ans.push_back(it.second) ;}
    return ans ;

}


vector<int> rightView(Node *root) {

    if(!root) {return {} ;}

    queue<pair<Node*, int>> q ; map<int, int> mp ;

    q.push({root, 0}) ;

    while(!q.empty()) {

        auto it = q.front() ; q.pop() ;

        Node* node = it.first ; int l = it.second ;

        if(!mp.count(l)) {

            mp[l] = node -> data ;
        }

        // then only difference is that we changed the direction of travelling a level from left->right to right->left
        if(node -> right){q.push({node -> right, l +1}) ;}
        if(node-> left) {q.push({node -> left, l +1}) ;}
    }

    vector<int> ans ; for(auto it : mp) {ans.push_back(it.second) ;}
    return ans ;

}