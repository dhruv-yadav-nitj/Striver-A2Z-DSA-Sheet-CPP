#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
// GFG Version -> we were asked to just return the merged vector and not tree so it was super easy (did only that much was asked in problem)

class Solution
{
public:
    vector<int> merge(Node *root1, Node *root2) {
        
        stack<Node*> st1 , st2 ;
		vector<int> in1, in2 ;
		Node* curr = root1 ;
		while(curr or !st1.empty()) {

			if(curr != NULL) {
				st1.push(curr) ; curr = curr -> left ;
			}
			else{
				in1.push_back(st1.top() ->data) ; curr = st1.top() -> right ;
				st1.pop() ;
			}
		}
		curr = root2 ;
		while(curr or !st2.empty()) {

			if(curr != NULL) {
				st2.push(curr) ; curr = curr -> left ;
			}
			else{
				in2.push_back(st2.top() ->data) ; curr = st2.top() -> right ;
				st2.pop() ;
			}
		}

		vector<int> ans ;
		int i = 0, j =0;
		while(i < in1.size() and j < in2.size()) {

			if(in1[i] < in2[j]) {
				ans.push_back(in1[i++]) ;
			}
			else{
				ans.push_back(in2[j++]) ;
			}
		}

		while(i < in1.size()) {
			ans.push_back(in1[i++]) ;
		}

		while(j < in2.size()) {
			ans.push_back(in2[j++]) ;
		}

		return ans ;
        
    }
};