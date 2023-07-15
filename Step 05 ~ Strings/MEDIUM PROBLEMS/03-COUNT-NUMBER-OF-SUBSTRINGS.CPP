#include <bits/stdc++.h>
using namespace std;

// could not understand this problem
// this code was copy pasted from some comment for reference

class Solution
{
public:
    long long int subwithk(string s, int k)
    {
        int arr[26] = {0};
        long long int count = 0;
        int distinct = 0;
        int i, left = 0;
        for (i = 0; i < s.length(); i++)
        {
            if (arr[s[i] - 'a'] == 0)
                distinct++;
            arr[s[i] - 'a']++;
            while (distinct > k)
            {
                arr[s[left] - 'a']--;
                if (arr[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }
            count += i - left + 1;
        }
        return count;
    }
    long long int substrCount(string s, int k)
    {
        // code here.
        return subwithk(s, k) - subwithk(s, k - 1);
    }
};