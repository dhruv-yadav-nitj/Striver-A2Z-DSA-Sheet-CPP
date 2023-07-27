#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/description/

// First understand properly the Problem #34 Count Inversion -> because this problem is completely based on that problem.

class Solution
{
public:
    int cnt = 0; // answer variable
    void merge(vector<int> &a, int l, int mid, int r)
    {

        int i = l, j = mid + 1;
        while (i <= mid and j <= r)
        {
            long long f = a[i] , h = a[j] ;
            if (f > 2*h)
            {
                cnt += (mid - i + 1);
                j++;
            }
            else
            {
                i++;
            }
        }

        // merge the both arrays into some sorted form

        i = l, j = mid + 1;
        vector<int> temp;
        while (i <= mid and j <= r)
        {
            if (a[i] <= a[j])
            {
                temp.push_back(a[i]);
                i++;
            }
            else
            {
                temp.push_back(a[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(a[i]);
            i++;
        }

        while (j <= r)
        {
            temp.push_back(a[j]);
            j++;
        }

        for (int i = l; i <= r; i++)
        {
            a[i] = temp[i - l];
        }
    }

    void divide(vector<int> &a, int l, int r)
    {

        if (l >= r)
        {
            return;
        }

        int mid = l + (r - l) / 2;

        divide(a, l, mid);
        divide(a, mid + 1, r);

        merge(a, l, mid, r);
    }

    int reversePairs(vector<int> &nums)
    {
        divide(nums, 0 , nums.size() -1) ; return cnt ;
    }
};