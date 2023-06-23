#include <bits/stdc++.h>
using namespace std;

// vvv good problem on graphs and djikstra'a algo
// article is also very good : https://takeuforward.org/graph/g-39-minimum-multiplications-to-reach-end/
// loved the intuition and approach

class Solution{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end){
        // code here

        int n = arr.size() ; int mod = 1e5 ;

        // this array would store the min number of multiplications it would take to reach a number
        vector<int> count (100000, 1e9) ; // distance array for djikstra algorithm
        // the numbers which are possible in this problem are 0 1 2 3 ... 99999 so treat them as nodes of the graph
        
        queue<pair<int, int>> q ; // <count of multiplications, node>

        count[start] = 0 ; q.push({0 , start}) ;
        while(!q.empty()) {
            int node = q.front().second, dis = q.front().first ;
            q.pop() ;

            if(node == end) {
                return dis ;
            }

            for(int i =0 ;i < n; i++) {
                int v = (node * arr[i]) % mod ;

                if(dis +1  < count[v]){
                    count[v] = dis + 1 ;
                    q.push({dis +1 , v}) ;
                } 
            }
        }

        return -1 ; // means was not reachable

    }
};