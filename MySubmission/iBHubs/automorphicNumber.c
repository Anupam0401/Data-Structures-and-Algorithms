#include <stdio.h>
#define mod 1000000007
long long int mul(long long int a, long long int b)
{
    a *= b;
    return (a >= mod ? a % mod : a);
}

long long int power(long long int a, long long int b)
{
    long long int result = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            result = mul(result, a);
        b >>= 1;
        a = mul(a, a);
    }
    return result;
}

int is_automorphic(long long int n)
{
    long long int count = 0;
    long long int temp = n;
    while (temp != 0)
    {
        temp /= 10; // n = n/10
        ++count;
    }
    if ((n * n) % power(10, count) == n)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t > 0)
    {
        long long int n;
        scanf("%lld", &n);
        is_automorphic(n) ? printf("Yes") : printf("No");

        if (t > 0)
        {
            printf("\n");
        }

        t--;
    }
    return 0;
}