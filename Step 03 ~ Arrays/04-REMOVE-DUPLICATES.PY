class Solution:	
    def remove_duplicate(self, A, N):
        # code here
        i =j =0 
        while (j < N) :
            if(j == N-1 or A[j] != A[j +1])  :
                A[i] = A[j]
                i +=1 
                j+=1
            else :
                j += 1
        return i
    
# if it was vector instead of arr then we have only one line solution using stl in c++
# using unique and erase function of stl