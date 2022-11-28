from fractions import Fraction
import numpy as np

def solution(m):
    if len(m) < 2:
        return [1,1]
    r_subm, q_subm = split_martix(m)
    f_subm = calc_f(q_subm)
    fr_subm = np.dot(f_subm, r_subm)
    return dec_to_frac_with_lcm(fr_subm[0])

def split_martix(m):
    absorbing = set()
    for row_i in range(len(m)):
        if sum(m[row_i]) == 0:
            absorbing.add(row_i)
    r_subm = []
    q_subm = []
    for row_i in range(len(m)):
        if row_i not in absorbing:
            row_total = float(sum(m[row_i]))
            r_temp = []
            q_temp = []
            for col_i in range(len(m[row_i])):
                if col_i in absorbing:
                    r_temp.append(m[row_i][col_i]/row_total)
                else:
                    q_temp.append(m[row_i][col_i]/row_total)
            r_subm.append(r_temp)
            q_subm.append(q_temp)
    return r_subm, q_subm

def calc_f(q_subm):
    return np.linalg.inv(np.subtract(np.identity(len(q_subm)), q_subm))

def dec_to_frac_with_lcm(l):
    ret_arr = []
    denoms = []
    for num in l:
        frac = Fraction(num).limit_denominator()
        ret_arr.append(frac.numerator)
        denoms.append(frac.denominator)
    lcd = 1
    for denom in denoms:
        lcd = lcm(lcd,denom)
    for num_i in range(len(ret_arr)):
        ret_arr[num_i] *= int(lcd/denoms[num_i])
    ret_arr.append(lcd)
    return ret_arr

def lcm(a, b):
    return abs(a*b) // gcd(a, b) if a and b else 0

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

print(solution([[0, 2, 1, 0, 0],
            [0, 0, 0, 3, 4],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0]]))

print(solution([[0, 1, 0, 0, 0, 1],
            [4, 0, 0, 3, 2, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0]]))
