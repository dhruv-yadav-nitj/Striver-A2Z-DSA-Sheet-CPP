//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// this question is just another version of book allocation problem --> concept is same but wording is different

class Solution
{
public:
    bool isValid(int arr[], int N, int D, int mid)
    {
        // loaded tracks that how much is the boat carrying at any moment and count tracks the days the boat is going to take if we assume the max loading capacity of boat to be mid
        // took count = 1  and not count = 0 to counter the end of loop case (do a dry run and you will understand)
        int loaded = 0, count = 1;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] + loaded <= mid)
            {
                loaded += arr[i];
            }
            else
            {
                count++;
                if (count > D or arr[i] > mid)
                {
                    return false;
                }
                loaded = arr[i];
            }
        }

        return (count <= D);
    }

    int leastWeightCapacity(int arr[], int N, int D)
    {
        // code here

        int low = 0, high = 0;
        for (int i = 0; i < N; i++)
        {
            high += arr[i];
        }

        int mid, ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (isValid(arr, N, D, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends