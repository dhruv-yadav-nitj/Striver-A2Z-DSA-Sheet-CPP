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

// first I though I should apply the vertical traversal approach (dividing each vertical column using the coordinate system) -> but that approach would be giving error for cases such as 1 3 10 5 7 9 N 5 5 9 2 10 where ans should be 5 but this apporach would give 4

// correct approach

// LeetCode Version
class Solution {
public:
    int getMaxWidth(Node *root) {

        if(!root) {return 0 ;}

        int ans = 0; queue<pair<Node*, int>> q ;

        q.push({root, 0}) ;

        while(!q.empty()) {

            int size= q.size() ;

            // to avoid integer overflow take a reference point (which would be the left most index in a level)
            int mini = q.front().second ;
            int leftMost, rightMost ;
            for(int k =0; k < size ; k++) {

                Node* curr= q.front().first ; int i = q.front().second - mini ; q.pop() ;
                
                if(k==0){leftMost = i ;}
                if(k == size-1) {rightMost= i ;}

                if(curr -> left){q.push({curr-> left, 2*i+1}) ;}
                if(curr -> right){q.push({curr-> right, 2*i+2}) ;}

            }

            ans = max(ans, rightMost - leftMost +1) ;

        }

        return ans ;
    }
};

// GfG Version (EASY)
class Solution {
public:
    int getMaxWidth(Node *root) {

        if(!root) {return 0 ;}

        int ans = 0; queue<Node*> q ; q.push(root) ;

        while(!q.empty()) {
            
            int size = q.size() ; // size of current level
            ans= max(ans, size) ;
            
            for(int i =0 ; i < size ; i++) {
                
                Node* curr = q.front() ; q.pop() ;
                
                if(curr -> left) {
                    q.push(curr -> left) ;
                }
                if(curr -> right) {
                    q.push(curr -> right) ;
                }
            }
        }

        return ans ;
    }
};