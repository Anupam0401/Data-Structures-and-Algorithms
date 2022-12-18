# Write a function:
# def solution (A)
# that, given an array A ofN integers, returns the sum of the largest odd intege
# and the largest even integer in A. If there are no odd or no even integers in A
# you can assume that the largest one in the corresponding group is 0 (look at
# examples 3 and 4 for comparison).
# Examples:
# Goven A = [5,3,10,6,11], the function should return 21

def solution(A):
    odd = 0
    even = 0
    for i in A:
        if i % 2 == 0:
            if i > even:
                even = i
        else:
            if i > odd:
                odd = i
    return odd + even