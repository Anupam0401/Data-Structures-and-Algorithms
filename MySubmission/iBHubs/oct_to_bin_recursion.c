#include <stdio.h>
#include <math.h>
#define mod 10000000007

long long int octal_to_decimal(long long int octal_number, long long int i);

long long int decimal_to_binary(long long int decimal_number, long long int i);

long long int octal_to_binary(long long int octal_number);

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

int main()
{
    long long int t;
    scanf("%lld", &t);
    while (t--)
    {
        long long int n;
        scanf("%lld", &n);
        printf("%lld\n", octal_to_binary(n));
    }
    return 0;
}

long long int octal_to_decimal(long long int octal_number, long long int i)
{
    if (octal_number == 0)
    {
        return 0;
    }
    return ((octal_number % 10) * power(8, i) + octal_to_decimal(octal_number / 10, ++i));
}

long long int decimal_to_binary(long long int decimal_number, long long int i)
{
    if (decimal_number == 0)
        return 0;
    return ((decimal_number % 2) * i + decimal_to_binary(decimal_number / 2, i * 10));
}

long long int octal_to_binary(long long int octal_number)
{
    long long int ans = 0;
    ans = octal_to_decimal(octal_number, 0);
    ans = decimal_to_binary(ans, 1);
    return ans;
}