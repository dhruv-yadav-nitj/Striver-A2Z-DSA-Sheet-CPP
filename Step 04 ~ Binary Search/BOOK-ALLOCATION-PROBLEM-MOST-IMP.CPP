#include <bits/stdc++.h>
using namespace std;

// its the most famous problem on Binary Search applied on search space, its because if you solved this problem then you can solve most of the problem based on this pattern i believe

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    bool isValid(int arr[], int n, int mid, int m)
    {
        // check function

        int allocated = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (allocated + arr[i] <= mid)
            {
                allocated += arr[i];
            }
            else
            {
                count++;
                // always remember this edge case -> most important
                if (arr[i] > mid or count > m)
                {
                    return false; // may be there's some book jisme no. of pages mid (jo ki hmari current limit hain) usase jyada ho -> most important edge case
                }
                allocated = arr[i];
            }
        }

    // possible cases :
        // if our current max limit of allocation to a single student (i.e. mid) is a value so small due to which we can allocate the available books to more than M students in that case we would obviously return false (and the function would increase low thus increasing mid)
        // but aisa bhi ho skta hain ki hmara jo allocation ka limit hain wo itna large ho ki hm available books ko M student mein allocate hi na kr paaye in that case we need to decrease the range i.e. high ko decrease krna hoga so that mid decrease ho ske
        // third case : mid is all perfect --> available books exactly M students mein allocate ho gye --> in that case we again need to decrease the range because we need to minimise the max pages allocated to a single student
        return true;
    }

    int findPages(int A[], int N, int M)
    {
        // code here

        int low = 0, high = 0;
        for (int i = 0; i < N; i++)
        {
            high += A[i];
        }

        // edge case --> what if the students are greater than books in that case we cant allocate min 1 book to each student
        if (M > N)
        {
            return -1;
        }

        int mid, ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (isValid(A, N, mid, M))
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
