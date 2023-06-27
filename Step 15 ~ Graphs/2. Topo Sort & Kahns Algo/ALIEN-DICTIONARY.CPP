#include <bits/stdc++.h>
using namespace std;

// [GOOD PROBLEM] -> intution is very important
// based on Kahns Algo

class Solution{
public:
    string findOrder(string dict[], int N, int K){
        // code here

        // think of this problem by imagining the roll list in your classroom (how the names are sorted accordingly, also ther's an edge case that if two students are name like Harsh Kumar and Harsh Verma then we would check until we dont get a character that helps us place one name before other so in this case starting letters in both the names are same until we encounter K and V using this we can tell K comes before V)

        vector<int> adj[K] ; // graph of size K since there are K different letters only

        for(int i=0 ; i < N - 1; i++){

            string s1 = dict[i] , s2 = dict[i +1] ;
            int len = min(s1.length() , s2.length()) ; int j = 0 ;
            while(j < len and s1[j] == s2[j]) {
                j++ ;
            }

            // now we arrived at some differentiating factor (letter) in both the names --> this letter is the reason we can keep s1 before s2 so we can say that s1[j] should come before s2[j]

            if(j< len){
                adj[s1[j]- 'a'].push_back(s2[j]- 'a') ; // char --> int (would make indexing in the array easy) , also this works since we are given only the letters from starting of the standard dictionary like if k = 4  (then we know that we have only a , b, c, d to consider) so , node 0 would be a , node 1  would be b and so on
            }
            // this even handles the edge case when if k > no. of unique characters in the dictionary 
            // like if in the same problem of k =5 but the words in the dict are same then we cant say anything about e .. but acc to our consideration (char to int) it would be a different node (node 4) (more precisely different component of our graph) having no edges connected to any other nodes
        }

        vector<int> indegree (K ,0) ; string order = "" ;
        for(int i =0  ;i < K ; i++){
            for(auto it: adj[i]) {
                indegree[it]++ ;
            }
        }

        queue<int> q ;
        for(int i =0 ; i < K ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        while(!q.empty()) {
            int node = q.front() ; q.pop() ;
            order += (char)(node + 'a') ;

            for(auto it : adj[node]) {
                indegree[it]-- ;
                if(indegree[it] ==0) {
                    q.push(it) ;
                }
            }
        }

        return order ;

    }
};