#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
#define lli long long int
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
using namespace std;

lli add(lli a, lli b)
{
    a += b;
    return (a >= mod ? a - mod : a);
}

lli sub(lli a, lli b)
{
    a -= b;
    return (a < 0 ? a + mod : a);
}

lli mul(lli a, lli b)
{
    a *= b;
    return (a >= mod ? a % mod : a);
}

lli power(lli a, lli b)
{
    lli result = 1;
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

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int diff(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int count_one = 0, count_zero = 0, c_one = 0, c_zero = 0, i;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count_zero++;
            else
                count_one++;
            if (i > 0 and s[i] != s[i - 1] and s[i - 1] == '0')
            {
                c_zero++;
            }
            else if (i > 0 and s[i] != s[i - 1] and s[i - 1] == '1')
            {
                c_one++;
            }
        }
        if (s[n - 1] == '1')
            c_one++;
        else
            c_zero++;
        //cout<<"c_one "<<c_one<<" c_zero "<<c_zero<<"\n";
        if (b <= 0)
            cout << a * count_one + a * (count_zero) + b * (MIN(c_one + 1, c_zero + 1)) << "\n";
        else
            cout << a * count_one + a * (count_zero) + b * (n) << "\n";
    }

    return 0;
}