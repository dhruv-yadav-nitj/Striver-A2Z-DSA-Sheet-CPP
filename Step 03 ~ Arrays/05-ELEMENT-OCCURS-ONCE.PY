class Solution:
    def search(self, A, N):
        # your code here
        ans =0
        for i in range (N) :
            ans = (ans ^ A[i])
        return ans
