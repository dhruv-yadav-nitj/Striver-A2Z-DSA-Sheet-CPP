#include <bits/stdc++.h>
using namespace std ;

// recursive approach
class Solution {
  public:
    void check (int num ,int r, int d, vector<int>&ans){
        if(num == r +1){
            return ;    
        }

        string s = to_string(num) ;
        if((s[0]-'0') == d or (s[s.length()-1]-'0')== d){
            check(num +1 , r , d , ans) ;
            return ;
        }

        int sum = s[s.length() - 1] -'0';
        for(int i=s.length() - 2 ; i >= 0 ; i--){
            if(s[i]-'0' <= sum or s[i]-'0'==d){check(num +1 , r , d , ans) ; return ;}
            sum += s[i]-'0' ;
        }
        ans.push_back(num) ;
        check(num +1 , r ,d , ans) ; return ;
    }
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> ans ; int l = L , r =R , d = D ;
        check(l , r , d , ans) ; sort(ans.begin(), ans.end()) ;
        return ans ;
    }
};

// iterative approach
class Solution {
  public:
  bool isValid (int n , int d){
      
      int digit = n%10 ;
      if(digit == d){
          return false ;
      }
      
      int sum = digit ;
      
      n /= 10 ;
      while(n > 0){
          digit = n%10 ;
          if(digit == d or digit <= sum){
              return false ;
          }
          else{
              sum += digit ;
              n /= 10 ;
          }
      }
      
      return true ;
      
  }
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int> ans ;
        for(int i = L ; i <= R ; i++){
            
            if(isValid (i , D)){
                ans.push_back(i) ;
            }
        }
        
        return ans ;
    }
};