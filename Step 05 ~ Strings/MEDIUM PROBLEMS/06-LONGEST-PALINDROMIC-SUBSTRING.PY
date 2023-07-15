# BRUTE FORCE APPROACH
class SolutionGFG:
    def longestPalin(self, S):
        # code here
        n = len(S)
        ans = ""
        for i in range (n) :
            temp = ""
            for j in range (i,n) :
                temp += S[j]
                rev = temp[::-1]
                if(temp == rev and len(temp) > len(ans)) :
                    ans = temp
        
        return ans


# OPTIMISED APPROACH
# https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution:
    def longestPalindrome(self, S: str) -> str:
        # code here
        n = len(S)
        res, cnt = "" , 0
        for i in range (n) :
            # ODD LENGTH SUBSTRING
            left = right = i
            while(left >=0 and right < n and S[left] == S[right]) :
                # if this new palindromic substring has length greater than existing ans -> copy the new one in ans
                if(right - left + 1 > cnt) :
                    res = S[left : right +1]
                    cnt = right - left + 1
                # move the pointers
                left -= 1
                right +=1
            
            # EVEN LENGTH SUBSTRING
            left, right = i , i +1
            while(left >=0 and right < n and S[left] == S[right]) :
                if(right - left + 1 > cnt) :
                    res = S[left : right +1]
                    cnt = right - left + 1
                left -= 1
                right +=1
        
        return res

# gfg has issues (giving TLE) -> leetcode works fine