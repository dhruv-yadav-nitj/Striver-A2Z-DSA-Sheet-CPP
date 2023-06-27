#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value; int weight;
};

class Solution {
public:
    static bool comparator (const pair<int, int>&a, const pair<int, int>&b) {
        double val1=  (double)a.first / (double)a.second ;
        double val2 = (double)b.first / (double)b.second ;

        return val1 > val2 ;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        
        // since its the fractional knapsack problem -> means we can break the items -> so to achieve max value we must take those items whose value/weight is more
        
        // step 1 : convert the given structure into some pair<int,int> vector
        vector<pair<int,int>> store;
        for(int i =0; i < n ; i++) {
            store.push_back({arr[i].value , arr[i].weight}) ;
        }
        
        // step 2 : sort the arr according to the decreasing (val / weight)
        sort(store.begin() , store.end() , comparator) ;

        double ans = 0 ;
        for(auto x : store) {
            int val = x.first , wt= x.second ;
            if(wt <= W) {
                ans = ans + val ; W = W- wt ;
            }
            else{
                // it means we have arrived at a item jiska wt hmare current capacity se jyada hain -> means we have to chose the max part we can store from this item and out knapsack would be completely filled
                ans = ans + (double)(val * W)/(double)wt ; break ;
            }
        }

        return ans ;

    }
};