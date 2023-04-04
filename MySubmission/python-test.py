# You are given an array A of N integers and an integer B. Count the number of pairs (i,j) such that A[i] + A[j] = B and i ≠ j. Since the answer can be very large, return the remainder after dividing the count with 109+7.

# Note - The pair (i,j) is same as the pair (j,i) and we need to count it only once.


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        dic={}
        count=0
        for i in A:
            if i in dic:
                dic[i]+=1
            else:
                dic[i]=1
        for i in A:
            if B-i in dic:
                if B-i==i:
                    count+=dic[i]-1
                else:
                    count+=dic[B-i]
        return count%(10**9+7)



