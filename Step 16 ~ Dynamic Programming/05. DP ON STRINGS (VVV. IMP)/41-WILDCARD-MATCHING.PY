# IMPORTANT AND DIFFERENT PROBLEM
class Solution:
    def stars (self, p:str, i:int) -> bool:
        for j in range(i+1) :
            if(p[j] != '*'):
                return False            
        return True
    
    def memo (self, s:str, p:str, i: int, j:int, dp:list) -> bool :
        # base case
        if(i < 0 and j <0):
            return True
        if(j < 0 and i >=0):
            return False
        if(i < 0 and j >=0):
            return self.stars(p, j)
        
        if(dp[i][j] != -1):
            return dp[i][j]
        
        if(s[i] == p[j] or p[j] == '?') :
            dp[i][j]=self.memo(s, p, i-1, j-1, dp)
            return dp[i][j]
        elif(p[j] == '*'):
            dp[i][j] = self.memo(s, p, i-1,j,dp) or self.memo(s, p, i, j-1, dp)
        else:
            dp[i][j] = False
        return dp[i][j]

    def isMatch(self, s: str, p: str) -> bool:
        n, m= len(s), len(p)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]
        return self.memo(s, p, n-1, m-1, dp)