# https://leetcode.com/problems/longest-increasing-subsequence/

# Recursive Solution

from typing import List
class Solution:
    def recursion (self, nums:List[int], curr:int, prev:int)->int:
        # base condition
        if curr == len(nums):
            return 0
        
        choose, notChoose = 0, 0
        notChoose = 0 + self.recursion(nums,curr+1,prev)
        if prev == -1 or nums[curr] > nums[prev]:
            choose = 1 + self.recursion(nums, curr+1, curr)
        return max(choose, notChoose)

    def memo (self, nums:List[int], curr:int, prev:int, dp:List[List[int]]) -> int:
        # base condition
        if curr >= len(nums):
            return 0
        
        if (dp[curr][prev +1]!= -1):
            return dp[curr][prev+1]
        
        choose, notChoose = 0, 0
        notChoose = 0 + self.memo(nums, curr+1, prev, dp)

        if prev == -1 or nums[curr] > nums[prev] :
            choose = 1 + self.memo(nums, curr+1, curr, dp)
        dp[curr][prev+1] = max(choose, notChoose)
        return dp[curr][prev+1]

    def lengthOfLIS(self, nums: List[int]):
        n = len(nums)
        dp = [[-1 for _ in range(n+1)] for _ in range(n)]
        # return self.memo(nums, 0, -1, dp)

        return self.tabulation(nums)
    
    # Time ~ O(n2)
    def tabulation (self, nums:List[int]) -> int:
        n = len(nums); dp = [1 for _ in range(n)]; maxi = 1
        for curr in range (n) :
            for prev in range (0, curr):
                if nums[prev] < nums[curr]:
                    dp[curr] = max (dp[curr] , 1 + dp[prev])
            maxi = max(maxi, dp[curr])
        return maxi