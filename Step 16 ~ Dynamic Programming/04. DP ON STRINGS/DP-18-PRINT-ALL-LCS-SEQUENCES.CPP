#include <bits/stdc++.h>
using namespace std;

// [HARD]

class Solution
{
public:
    void allLCSUtil(string s, string t, vector<vector<int>> &dp, set<string> &ans, int x, int y, string lcs, int len)
    {
        if (lcs.length() == len)
        {
            reverse(lcs.begin(), lcs.end());
            ans.insert(lcs);
            return;
        }
        for (int i = x; i > 0; i--)
        {
            for (int j = y; j > 0; j--)
            {
                if (s[i - 1] == t[j - 1])
                    allLCSUtil(s, t, dp, ans, i - 1, j - 1, lcs + s[i - 1], len);
            }
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int x = s.length(), y = t.length();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1));
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        set<string> ans;
        allLCSUtil(s, t, dp, ans, x, y, "", dp[x][y]);
        vector<string> result;
        for (auto i : ans)
            result.push_back(i);
        return result;
    }
};
