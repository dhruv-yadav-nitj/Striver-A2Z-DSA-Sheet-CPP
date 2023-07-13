class Solution:
    def romanToDecimal(self, S):
        # code here

        # dictionary to store the roman letter wrt to its decimal equivalent
        dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        ans =0

        for i in range (len(S)) :
            if(i > 0 and dict[S[i]] > dict[S[i-1]]) :
                ans += dict[S[i]] - 2 * dict[S[i-1]]
            else :
                ans += dict[S[i]]

        return ans
