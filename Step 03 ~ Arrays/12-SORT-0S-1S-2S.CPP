#include <bits/stdc++.h>
using namespace std;

// most optimised and O(n) solution
// using three pointers to track the position of last 0, 1, and first 2
class Solution {
public:
    void sort012(int a[], int n) {
        // code here
        int zero=0 , one = 0 , two = n-1 ;
        while(one <= two) {
            if(a[one] == 1) {
                one++ ;
            }
            else if(a[one] == 0) {
                swap(a[zero++] , a[one++]) ;
            }
            else{
                swap(a[one] , a[two--]) ;
            }
        }
    }
};