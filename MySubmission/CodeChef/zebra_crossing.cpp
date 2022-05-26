#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define lli long long int
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
int n, k, i, t, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        c = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
                c++;
        }
        if (c >= k)
        {
            for (i = n - 1; i >= 1; i--)
            {
                if (k % 2 == 0 && s[i] == s[0])
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
            for (i = n - 1; i >= 1; i--)
            {
                if (k % 2 && s[i] != s[0])
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}