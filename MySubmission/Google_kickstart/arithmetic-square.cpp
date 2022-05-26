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
        lli g[3][3], ans = 0, i, j, temp[4];
        cin >> g[0][0] >> g[0][1] >> g[0][2] >> g[1][0] >> g[1][2] >> g[2][0] >> g[2][1] >> g[2][2];

        temp[0] = ((g[0][0] + g[2][2]) % 2 == 0) ? (g[0][0] + g[2][2]) / 2 : 1000000001;
        temp[1] = ((g[2][0] + g[0][2]) % 2 == 0) ? (g[2][0] + g[0][2]) / 2 : 1000000002;
        temp[2] = ((g[1][0] + g[1][2]) % 2 == 0) ? (g[1][0] + g[1][2]) / 2 : 1000000003;
        temp[3] = ((g[0][1] + g[2][1]) % 2 == 0) ? (g[0][1] + g[2][1]) / 2 : 1000000004;
        int max = 0;
        for (i = 0; i < 4; i++)
        {
            int f = 0;
            if (temp[i] <= 1000000000 && ans < 1)
                ans += 1;
            for (j = 0; j < 4; j++)
            {
                if (temp[i] == temp[j] && i != j)
                    f++;
            }
            if (f >= max)
                max = f;
        }
        ans += (max > 0) ? max : 0;
        // cout << ans << " ";
        if (isAP(g[2][0], g[2][2]) == g[2][1])
            ans++;
        if (isAP(g[2][2], g[0][2]) == g[1][2])
            ans++;
        if (isAP(g[0][0], g[0][2]) == g[0][1])
            ans++;
        if (isAP(g[2][0], g[0][0]) == g[1][0])
            ans++;

        cout << "Case #" << p << ": " << ans << endl;
    }
    return 0;
}