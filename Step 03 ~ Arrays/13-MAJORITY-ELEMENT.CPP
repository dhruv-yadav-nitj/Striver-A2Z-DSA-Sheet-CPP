#include <bits/stdc++.h>
using namespace std;

// optimised approach (though there are many different other ways to do this problem)
// moore's voting algorithm
class Solution {
public:
    int majorityElement(int a[], int size) {
        // your code here
        int cnt =0 , element ;
        for(int i =0; i< size ; i++) {
            if(cnt ==0) {element=  a[i] ; cnt =1 ;}
            else if(element == a[i]) {
                cnt++ ;
            }
            else{
                cnt-- ;
            }
        }

        // since the problem may or may not contain majority element -> so we need to check if the variable 'element' is storing the correct element or not (since it will always store some element from array, accoriding to the algorithm)

        int cnt1 =0 ;
        for(int i =0 ; i < size; i++) {
            if(a[i] == element) {cnt1++ ;}
        }
        
        if(cnt1 > (size/2)) {return element ;}
        else{return -1 ;}
    }
};