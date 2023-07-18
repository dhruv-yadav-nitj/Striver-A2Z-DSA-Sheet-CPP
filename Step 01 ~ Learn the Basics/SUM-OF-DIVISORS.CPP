#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

class Solution
{
public:
    long long sumOfDivisors(int N) {
        // Write Your Code here

        long long ans = 0;
        for (int j = 1; j <= N; j++) {
            int n = j;
            for (int i = 1; i <= sqrt(n); i++) {

                if (n % i == 0) {
                    ans += i;
                    if (i != n / i) { ans += n / i; }
                }
            }
        }

        return ans;
    }
};