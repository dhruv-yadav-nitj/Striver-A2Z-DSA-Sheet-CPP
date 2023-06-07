#include <bits/stdc++.h>
using namespace std;

// approach #1
class Solution{
public:
    long long divide(long long dividend, long long divisor){
        // code here

        long long ans = 0;
        while (dividend >= divisor){

            ans++;
            dividend = dividend - divisor;
        }

        return ans;
    }
};

// approach #2 : optimised : O(1) ~ Time Complexity
// https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
class Solution{
public:
    long long divide(long long dividend, long long divisor){
        // code here

        int sign = 1; // consider positive
        // sign would be -ve when only one of them would be negative
        if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0)){
            sign = -1;
        }

        dividend = abs(dividend), divisor = abs(divisor);

        long long quotient = 0, temp = 0;
        for (int i = 31; i >= 0; --i){

            if (temp + (divisor << i) <= dividend){
                temp += divisor << i;
                quotient |= 1LL << i;
            }
        }

        if (sign == -1){quotient = -quotient;}

        return quotient;
    }
};