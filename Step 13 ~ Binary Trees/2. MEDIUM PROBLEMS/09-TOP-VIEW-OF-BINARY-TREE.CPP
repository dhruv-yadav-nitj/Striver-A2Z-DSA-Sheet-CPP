#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node *root) {
        
        if(!root) {return {} ;}

        map<int, int> mp ; // <vertical level, node value> 

        // why use map ? -> since we know map stores the data in sorted manner and we also want the nodes from leftmost side (having smallest vertical level) to rightmost side (having largest vertical level) -> so we used map to store the top most nodes of each vertical level and in sorted vertical level format

        queue<pair<Node*, int>> q ; q.push({root, 0}) ;

        while(!q.empty()) {

            auto it = q.front() ; q.pop() ;
            Node* node =it.first ; int v = it.second;

            // since we are travelling in level order wise -> so if a vertical is filled already in map then it is sure that the top most node in already in the map -> bcz neeche waale node to baad hi mein aaenge na uppar waale se
            if(mp.find(v) == mp.end()) {mp[v]= node -> data ;}

            if(node -> left) {q.push({node-> left, v -1}) ;}
            if(node -> right) {q.push({node-> right, v + 1}) ;}

        } 

        vector<int> ans ;

        for(auto it : mp) {ans.push_back(it.second) ;}

        return ans ;

    }
};