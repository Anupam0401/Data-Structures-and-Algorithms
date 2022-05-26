#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000000000007
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        lli n, k, ans, e, o;
        cin >> n;
        k = n / 6;
        if (n % 2 == 0)
        {
            e = n / 2;
            o = n / 2;
            ans = 3 * (e - k) + 2 * o + 4 * k;
            ans = ans % 1000000007;
        }
        else
        {
            e = n / 2;
            o = e + 1;
            ans = 3 * (e - k) + 2 * o + 4 * k;
            ans = ans % 1000000007;
        }
        cout << ans << endl;
    }
    return 0;
}