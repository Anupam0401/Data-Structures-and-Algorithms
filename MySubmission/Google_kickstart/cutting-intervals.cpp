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

lli isAP(lli a, int b)
{
    return ((a + b) % 2 == 0) ? (a + b) / 2 : 1000000006;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        lli a[10000 + 1] = {0};
        lli n, c;
        cin >> n >> c;
        for (lli i = 0; i < n; i++)
        {
            lli l, r;
            cin >> l >> r;
            for (lli j = l + 1; j < r; j++)
            {
                a[j]++;
            }
        }
        priority_queue<lli> max;
        for (lli i = 1; i <= 10000; i++)
        {
            if (a[i])
                max.push(a[i]);
        }
        lli ans = n;
        while (!max.empty() and c)
        {
            ans += max.top();
            max.pop();
            c--;
        }
        cout << "Case #" << p << ": " << ans << "\n";
    }
    return 0;
}