# https://leetcode.com/problems/number-of-longest-increasing-subsequence/
from typing import List
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1 for _ in range(n)]; maxi=1
        count = [1 for _ in range(n)]
        for curr in range(n):
            for prev in range(curr) :
                if nums[curr] > nums[prev] and dp[curr] < dp[prev] + 1:
                    dp[curr] = max(dp[curr], 1 + dp[prev])
                    count[curr] = count[prev] # inherit the count
                elif nums[curr] > nums[prev] and dp[curr] == dp[prev] + 1:
                    count[curr] += count[prev] # increase the count
            maxi = max(maxi, dp[curr])
        cnt = 0
        for i in range(0, n):
            if dp[i] == maxi:
                cnt += count[i]
        return cnt