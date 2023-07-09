
# https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1
# i better do code in python when values give int overflow or something in c++

class Solution:
    def maxOdd(self, s):
        temp = ""
        maxi = 0
        for i in range(0 , len(s)) :
            temp = temp + s[i]
            a = int(temp)
            if (a%2==1) :
                maxi = max(maxi, a)
        
        if(maxi == 0) :
            return ""
        else :
            return maxi