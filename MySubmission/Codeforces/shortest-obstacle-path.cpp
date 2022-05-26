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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int xa, ya, xb, yb, xf, yf, ans;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        if (xa == xb)
        {
            if (xb == xf && MIN(ya, yb) < yf && yf < MAX(ya, yb))
                ans = diff(ya, yb) + 2;
            else
                ans = diff(ya, yb);
        }
        else if (ya == yb)
        {
            if (yb == yf && MIN(xa, xb) < xf && xf < MAX(xa, xb))
                ans = diff(xa, xb) + 2;
            else
                ans = diff(xa, xb);
        }
        else
        {
            ans = diff(xa, xb) + diff(ya, yb);
        }
        cout << ans << endl;
    }
    return 0;
}
