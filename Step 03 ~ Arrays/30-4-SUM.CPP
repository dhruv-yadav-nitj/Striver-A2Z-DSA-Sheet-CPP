#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        // code here
        set<vector<int>> st; int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> st2;
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j]; sum += nums[k];
                    long long req = target - sum;
                    if (st2.count(req)) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)req};
                        sort(temp.begin(), temp.end()); st.insert(temp);
                    }
                    st2.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};