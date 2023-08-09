#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution {
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
        
        pre = NULL , suc = NULL ;

        Node* curr = root ;
        while(curr) {
            // if the curr node is greater than the key than it is a possible candidate for inorder successor -> update the ans and move to left to search for even more smaller value
            if(curr->key > key) {
                suc = curr ;
                curr = curr -> left ;
            }
            else{
                curr = curr -> right ;
            }
        }

        curr =root ;
        while(curr){
            // if the curr node is smaller than the key then its a possible candidate for inorder predecessor -> update the ans and search for even greater element which can be smaller than key
            if(curr -> key < key) {
                pre = curr ; curr = curr -> right; 
            }
            else{
                curr = curr -> left ;
            }
        }
    }
};