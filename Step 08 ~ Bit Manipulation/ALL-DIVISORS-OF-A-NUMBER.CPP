#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_divisors(int n)
    {
        // Code here.

        // already done in Learn the Basics

        set<int> s;
        for (int i = 1; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                s.insert(i);

                if (n / i != i)
                {
                    s.insert(n / i);
                }
            }
        }

        for(auto it : s){
            cout << it << " " ;
        }
    }
};