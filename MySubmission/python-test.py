# You are given a n x n 2D matrix A representing an image.

# Rotate the image by 90 degrees (clockwise).

class Solution:
    # @param A : list of list of integers
    def solve(self, A):
        newMatrix=[]
        for i in range(len(A)):
            newMatrix.append([])
            for j in range(len(A)):
                newMatrix[i].append(0)
        for i in range(len(A)):
            for j in range(len(A)):
                newMatrix[i][j]=A[len(A)-1-j][i]
        return newMatrix