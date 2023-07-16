class Solution:

	def print2largest(self,arr, n):
		# code here
		a = b= -1
		for i in range (n) :
		    if(arr[i] > a) :
		        b = a
		        a = arr[i]
            elif (arr[i] > b and arr[i] < a) :
                b = arr[i]
        return b
