#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarysearch(int arr[], int n, int k)
    {
        // code here

        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == k)
            {
                return mid;
            }
            else if (arr[mid] > k)
            {
                high--;
            }
            else
            {
                low++;
            }
        }

        return -1;
    }
};