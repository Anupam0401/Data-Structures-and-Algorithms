# Given a list of distinct positive integers named pegs representing the location of each peg along the support beam, write a function solution(pegs) which, if there is a solution, returns a list of two positive integers a and b representing the numerator and denominator of the first gear's radius in its simplest form in order to achieve the goal above, such that radius = a/b. The ratio a/b should be greater than or equal to 1. Not all support configurations will necessarily be capable of creating the proper rotation ratio, so if the task is impossible, the function solution(pegs) should return the list [-1, -1].

# For example, if the pegs are placed at [4, 30, 50], then the first gear could have a radius of 12, the second gear could have a radius of 14, and the last one a radius of 6. Thus, the last gear would rotate twice as fast as the first one. In this case, pegs would be [4, 30, 50] and solution(pegs) should return [12, 1].

# The list pegs will be given sorted in ascending order and will contain at least 2 and no more than 20 distinct positive integers, all between 1 and 10000 inclusive.

def solution(pegs):
    return answer(pegs)

from fractions import Fraction  
def answer(pegs):
    size = len(pegs)
    if ((not pegs) or size == 1):
        return [-1,-1]

    even = True if (size % 2 == 0) else False
    sum = (- pegs[0] + pegs[size - 1]) if even else (- pegs[0] - pegs[size -1])

    if (size > 2):
        for index in range(1, size-1):
            sum += 2 * (-1)**(index+1) * pegs[index]

    firstGR = Fraction(2 * (float(sum)/3 if even else sum)).limit_denominator()

    if firstGR < 2:
        return [-1,-1]

    currR = firstGR
    for index in range(0, size-2):
        centreD = pegs[index+1] - pegs[index]
        nextR = centreD - currR
        if (currR < 1 or nextR < 1):
            return [-1,-1]
        else:
            currR = nextR

    return [firstGR.numerator, firstGR.denominator]
    


print(solution([4, 30, 50]))
print(solution([4, 17, 50]))