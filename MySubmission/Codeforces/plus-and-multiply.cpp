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
        lli n, a, b;
        int f = 0;
        cin >> n >> a >> b;
        for (lli i = 1; i <= n; i = i * a)
        {
            if ((n - i) % b == 0)
            {
                f = 1;
                break;
            }
            if (a == 1)
                break;
        }

        if (f == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}