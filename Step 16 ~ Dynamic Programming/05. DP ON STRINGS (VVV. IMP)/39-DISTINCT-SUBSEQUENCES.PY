# DIFFERENT PATTERN FROM PREV PROBLEMS
class Solution:
    def numDistinct(self, s: str, t: str)-> int:
        # main function
        # return self.recursion(s,t,len(s)-1, len(t)-1)

        # creating dp list
        n, m = len(s), len(t)
        dp = [[-1 for _ in range(m)] for _ in range (n)]
        # the underscore character (_) is often used as a variable name when you don't intend to use the value of that variable.
        # The in range(m) part in the for _ in range(m): statement is used to create a loop that iterates over a sequence of numbers from 0 to m-1.
        return self.memo(s, t,n-1, m-1, dp)

    def recursion(self, s: str, t:str, i:int, j:int)-> int:
        # base condition
        if(j <0): return 1 # if t gets consumed
        if(i <0): return 0 # if s gets consumed
        ans =0
        if(s[i]==t[j]):
            # we have two options -> choose the current index in s or not
            ans = self.recursion(s, t, i-1, j-1) + self.recursion(s, t, i-1, j)
        else:
            ans = self.recursion (s, t, i-1, j)
        return ans
    def memo (self, s:str, t:str, i:int, j:int, dp)->int:
        # base condition
        if(j<0):return 1
        if(i<0):return 0

        if(dp[i][j] != -1):
            return dp[i][j]
        
        # case 1: if both characters match
        ans =0
        if(s[i] == t[j]):
            dp[i][j] = self.memo(s, t, i-1, j, dp)+self.memo(s, t, i-1, j-1, dp)
            return dp[i][j]
        else:
            dp[i][j] = self.memo(s, t, i-1, j, dp)
            return dp[i][j]

