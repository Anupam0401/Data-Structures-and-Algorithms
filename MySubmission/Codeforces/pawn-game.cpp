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
    lli t;
    cin >> t;
    while (t--)
    {
        lli n, i, ans = 0;
        cin >> n;
        char e[n], m[n];
        for (i = 0; i < n; i++)
        {
            cin >> e[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> m[i];
            if (m[i] == '1' && e[i] == '0')
            {
                ans++;
                m[i] = '0';
                // cout << "middle\n";
            }
        }
        if (e[1] == '1' && m[0] == '1')
        {
            ans++;
            e[1] = '0';
            m[0] = '0';
            // cout << "first\n";
        }
        if (e[n - 2] == '1' && m[n - 1] == '1')
        {
            ans++;
            e[n - 2] = '0';
            m[n - 1] = '0';
            // cout << "last\n";
        }
        for (i = 1; i < n - 1; i++)
        {
            if (m[i] == '1')
            {
                if (e[i - 1] == '1')
                {
                    ans++;
                    e[i - 1] = '0';
                    // cout << "left\n";
                }
                else if (e[i + 1] == '1')
                {
                    ans++;
                    e[i + 1] = '0';
                    // cout << "right\n";
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}