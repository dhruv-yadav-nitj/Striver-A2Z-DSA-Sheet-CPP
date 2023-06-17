//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// was super super hard for me (could not solve it that time though)
// did not solved myself
class Solution
{
public:
    void dfs(int index, string s, int target, vector<string> &ans, string temp, long long prev, long long res)
    {
        // base case
        if (index == s.size())
        {
            if (res == target)
            {
                ans.push_back(temp);
            }
            return;
        }

        string st = "";
        long long curr = 0;
        for (int j = index; j < s.size(); j++)
        {
            if (j > index and s[index] == '0')
            {
                break;
            }
            st += s[j];
            curr = curr * 10 + (s[j] - '0');
            if (index == 0)
            {
                dfs(j + 1, s, target, ans, temp + st, curr, curr);
            }
            else
            {
                dfs(j + 1, s, target, ans, temp + "+" + st, curr, res + curr);
                dfs(j + 1, s, target, ans, temp + "-" + st, -curr, res - curr);
                dfs(j + 1, s, target, ans, temp + "*" + st, prev * curr, res - prev + prev * curr);
            }
        }
    }

public:
    vector<string> addOperators(string s, int target)
    {
        vector<string> ans;
        string temp = "";
        long long prev = 0;
        dfs(0, s, target, ans, temp, prev, 0);
        return ans;
    }
};
