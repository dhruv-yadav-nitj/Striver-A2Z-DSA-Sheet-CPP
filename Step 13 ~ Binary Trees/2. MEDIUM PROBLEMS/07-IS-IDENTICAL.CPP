#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

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

// approach : koi bhi ek traversal kr ke dekh lo agar dono nodes same nhi hain then return false and agar same hain then check further

class Solution
{
    public:
    //Function to check if two trees are identical.
    
    bool check (Node* node1, Node* node2) {
        
        // case 1 : if both are nuLL -> return true
        if(!node1 and !node2) {
            return true ;
        }
        // if koi ek nULL hain sirf -> return false;
        if((!node1 and node2) or (node1 and !node2)) {
            return false ;
        }
        // if both nodes represent different datas -> return false here only, no need to check further
        if(node1 -> data != node2-> data)  {
            return false ;
        }
        // if both nodes have same data then check further -> check left -> if true -> check right ; else -> return false
        if(check(node1-> left, node2-> left)) {
            return check(node1 -> right, node2-> right) ;
        }
        else{
            return false;
        }
        
    }
    
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        return check(r1, r2) ;
    }
};