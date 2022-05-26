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
        int n, k, bin[32] = {0}, max = 0;
        cin >> n >> k;
        lli a[n], i, op = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            for (int j = 31; j >= 0; j--)
            {
                lli p = a[i] >> j;
                if (p & 1)
                {
                    bin[j] += 1;
                    if (j > max)
                        max = j;
                }
            }
        }
        for (int j = max; j >= 0; j--)
        {
            if (bin[j] > 0)
            {
                if (bin[j] <= k)
                    op += 1;
                else
                {
                    if (n > k)
                    {
                        if (bin[j] % k == 0)
                            op += bin[j] / k;
                        else
                            op += (bin[j] / k) + 1;
                    }

                    else
                        op += 1;
                }
            }
        }
        cout << op << endl;
    }
    return 0;
}