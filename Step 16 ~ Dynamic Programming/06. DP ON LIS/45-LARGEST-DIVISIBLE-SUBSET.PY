# https://leetcode.com/problems/largest-divisible-subset/
# https://takeuforward.org/data-structure/longest-divisible-subset-dp-44/
# very good explanation in the above article
from typing import List
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort(); n = len(nums)
        dp = [1 for _ in range(n)]; hash= [_ for _ in range(n)]

        maxi, last =1, 0
        for i in range(n):
            for prev in range(0,i) :
                if nums[i]%nums[prev]==0 and dp[i] < dp[prev]+1:
                    dp[i] = 1 + dp[prev]
                    hash[i]= prev
                    last = i if (maxi < dp[i]) else last
                    maxi = max(maxi, dp[i])
        ans=[]
        while True :
            ans.append(nums[last])
            if (last == hash[last]):
                break
            last = hash[last]
        return ans[::-1]