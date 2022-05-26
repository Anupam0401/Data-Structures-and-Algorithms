T = int(input())
for i in range(T):
    m, n, p = map(int, input().split())
    ans = n + (100 - m) * p
    result = ans * 10
    print(result)