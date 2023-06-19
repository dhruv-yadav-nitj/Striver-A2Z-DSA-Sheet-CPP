#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// ekdam similar to previous problem

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int solve(int arr[], int n)
    {
        if (n == 1)
        {
            return arr[0];
        }

        int prev2, prev1, curr;
        prev2 = arr[0], prev1 = max(arr[1], 0 + arr[0]);
        for (int i = 2; i < n; i++)
        {
            curr = max(arr[i] + prev2, 0 + prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // simply apply the concept used in max sum of non adjacent element (DP - 05) and in vs code dp-07
        return solve(arr, n);
    }
};