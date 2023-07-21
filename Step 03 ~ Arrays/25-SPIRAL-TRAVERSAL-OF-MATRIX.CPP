#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int top(0), left(0), right(matrix[0].size() - 1), bottom(matrix.size() - 1);
        // what we have to do is to change the above declared variables after every iteration
        // we have to increase the startTop++ , startLeft--, startRight++, startBottom--
        int rowNum(matrix.size()), colNum(matrix[0].size());

        // count is the number of elements printed till now and total is the total number of elements present in the matrix
        int count(0), total(rowNum * colNum);
        while (count < total)
        {
            // lets print the top most row of the present matrix
            for (int j = left; j <= right and count < total; j++)
            {
                ans.push_back(matrix[top][j]);
                count++;
            }top++;

            // lets print the right most columns of the present matrix
            for (int i = top; i <= bottom and count < total; i++)
            {
                ans.push_back(matrix[i][right]);
                count++;
            }right--;

            // lets print the bottom most row of the present matrix
            for (int j = right; j >= left and count < total; j--)
            {
                ans.push_back(matrix[bottom][j]);
                count++;
            }bottom--;

            // lets print the left most column of the present matrix
            for (int i = bottom; i >= top and count < total; i--)
            {
                ans.push_back(matrix[i][left]);
                count++;
            }left++;
        }
        return ans;
    }
};