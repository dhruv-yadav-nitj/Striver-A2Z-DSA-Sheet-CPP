#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

class Solution {
public:
    vector<int> KDistanceNodes(Node *root, int target, int k) {

        // first store the parent of all the nodes in some hash table which makes the upward traversal from a node possible

        unordered_map<Node*, Node*> mp ;
        queue<Node*> q ; q.push (root) ; mp[root]= NULL ;

        Node* node = NULL ;

        while(!q.empty()) {

            Node* curr = q.front() ; q.pop() ;

            if(curr -> data == target and !node) {node = curr ;}

            if(curr -> left) {
                mp[curr -> left] = curr ;
                q.push(curr -> left) ;
            }
            if(curr ->right) {
                mp[curr -> right] = curr ;
                q.push(curr -> right) ;
            }
        }

        vector<int> ans ;
        unordered_map<Node*, bool> isVisited ;
        queue<pair<Node*, int>> pq ; pq.push({node, 0}) ;

        isVisited[node] = true ;


        while(!pq.empty())  {

            auto it = pq.front() ; pq.pop() ;

            Node* curr = it.first ; int dis = it.second ;

            if(dis > k){break ;} // since we are traversing level wise, so the distance would increase by unit step -> so once the distance exceeds k -> just break bcz no logic to check further

            if(dis == k) {ans.push_back(curr-> data) ;}

            if(curr -> left and !isVisited[curr-> left]) {
                pq.push({curr -> left, dis +1});
                isVisited[curr->left] = true ;
            }
            if(curr -> right and !isVisited[curr-> right]){
                pq.push({curr -> right, dis +1});
                isVisited[curr-> right] = true ;
            }
            if(mp[curr] and !isVisited[mp[curr]]){
                pq.push({mp[curr], dis +1}) ;
                isVisited[mp[curr]] = true ;
            }
        }

        sort(ans.begin() , ans.end()) ; return ans ;
        
    }
};