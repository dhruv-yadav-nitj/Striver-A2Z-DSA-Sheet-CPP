# https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
class Solution:
    def longestIncreasingSubsequence(self, n:int, arr:list)-> list:
        dp = [1 for _ in range(n)]
        hash = [1 for _ in range(n)]

        for curr in range(0, n):
            hash[curr] = curr
            for prev in range(0, curr):
                if(arr[curr] > arr[prev] and 1 + dp[prev] > dp[curr]):
                    dp[curr]= 1+ dp[prev]
                    hash[curr] = prev
        ans, last= -1, -1
        for i in range(0, n):
            if ans < dp[i]:
                ans = dp[i]
                last = i
        
        temp = [] ; temp.append(arr[last])
        while hash[last] != last :
            last = hash[last]
            temp.append(arr[last])
        
        temp.reverse()
        return temp