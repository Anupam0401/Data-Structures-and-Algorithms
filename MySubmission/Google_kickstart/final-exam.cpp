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

lli go_left(lli a[], lli x)
{
    for (lli i = x; i >= 1; i--)
    {
        if (a[i] > 0)
            return i;
    }
    return 0;
}

lli go_right(lli a[], lli x)
{
    for (lli i = x; i <= 1000; i++)
    {
        if (a[i] > 0)
            return i;
    }
    return 1001;
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
        lli n, m, a[1001] = {0}, i, j;
        cin >> n >> m;
        lli ans[m];
        for (j = 0; j < n; j++)
        {
            lli l, r;
            cin >> l >> r;
            for (i = l; i <= r; i++)
            {
                a[i]++;
            }
        }
        lli left, right;
        for (i = 0; i < m; i++)
        {
            lli s;
            cin >> s;
            left = go_left(a, s);
            right = go_right(a, s + 1);

            if (left == 0)
            {
                ans[i] = right;
                a[right] = 0;
            }
            else if (right == 1001)
            {
                ans[i] = left;
                a[left] = 0;
            }
            else if (abs(left - s) <= abs(right - s))
            {
                ans[i] = left;
                a[left] = 0;
            }
            else
            {
                ans[i] = right;
                a[right] = 0;
            }
        }
        cout << "Case #" << p << ": ";
        for (i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}