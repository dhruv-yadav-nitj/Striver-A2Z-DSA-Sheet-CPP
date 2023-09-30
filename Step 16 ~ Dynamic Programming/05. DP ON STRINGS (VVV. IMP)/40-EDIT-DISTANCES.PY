# DIFFERENT PATTERN FROM PREV PROBLEMS
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[-1 for _ in range(m)] for _ in range(n)]
        return self.memo(word1, word2, n-1, m-1, dp)

    def memo (self, word1, word2, i, j, dp) :
        # base case
        if(i < 0) :
            # if string 1 gets consumed completely -> we need to Add the rem characters of string 2 one by one
            return j+1
        if(j < 0) :
            # if string 2 gets consumed early -> we need to remove the rem characters of word 1 one by one
            return i+1
        
        if(dp[i][j] != -1):
            return dp[i][j]
        
        if(word1[i] == word2[j]):
            dp[i][j] = self.memo(word1, word2, i-1, j-1, dp)
            return dp[i][j]
        else:
            # then we can either insert, remove or replace
            dp[i][j] = 1 + min(self.memo(word1, word2, i, j-1, dp), self.memo(word1, word2, i-1, j, dp), self.memo(word1, word2, i-1, j-1, dp))
            return dp[i][j]