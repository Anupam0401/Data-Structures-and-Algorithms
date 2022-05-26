import sys
from math import factorial




# Take the input string which may contain whitespaces at the end


k = int(input())
p = int(input())
sum = 0
for i in range(0,k):
    sum += (k*p)**i/factorial(i)

sum+=(k*p)**k/(factorial(k)*(1-p))
sum= 1/sum
sum *= (k*p)**k/(factorial(k)*(1-p))
print(sum)


