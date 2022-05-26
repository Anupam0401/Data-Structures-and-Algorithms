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
        int h, w;
        cin >> h >> w;
        int ans[h][w] = {0}, i, j;
        for (j = 0; j < w; j++)
        {
            ans[0][j] = !(j & 1);
        }
        for (j = 1; j < h; j++)
        {
            ans[j][0] = !ans[j - 1][0];
        }
        ans[h - 1][1] = 0;
        for (j = 2; j < w; j++)
        {
            ans[h - 1][j] = !ans[h - 1][j - 1];
        }
        ans[1][w - 1] = 0;
        for (j = 2; j < h - 1; j++)
        {
            ans[j][w - 1] = !ans[j - 1][w - 1];
        }
        if (ans[h - 1][w - 2] == 0 && ans[h - 2][w - 1] == 1)
            ans[h - 1][w - 1] = 0;
        if (ans[h - 1][w - 2] == 1 && ans[h - 2][w - 1] == 1)
            ans[h - 2][w - 1] = 0;

        for (i = 0; i < h; i++)
        {
            for (j = 0; j < w; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}