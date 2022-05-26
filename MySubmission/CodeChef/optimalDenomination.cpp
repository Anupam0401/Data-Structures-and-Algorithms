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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        lli a[n], i, left_gcd[n] = {0}, right_gcd[n] = {0}, hcf[n] = {0}, key, bakra, ans = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1 || n == 2)
        {
            ans = n;
        }
        else
        {
            left_gcd[1] = a[0];
            for (i = 2; i < n; i++)
            {
                left_gcd[i] = gcd(left_gcd[i - 1], a[i - 1]);
            }
            right_gcd[n - 2] = a[n - 1];
            for (i = n - 3; i >= 0; i--)
            {
                right_gcd[i] = gcd(right_gcd[i + 1], a[i + 1]);
            }
            hcf[0] = right_gcd[0];
            hcf[n - 1] = left_gcd[n - 1];
            key = MAX(hcf[0], hcf[n - 1]);
            bakra = (hcf[0] == hcf[n - 1]) ? MAX(a[0], a[n - 1]) : (hcf[0] > hcf[n - 1]) ? a[0]
                                                                                         : a[n - 1];
            for (i = 0; i < n; i++)
            {
                if (i >= 1 && i < n - 1)
                    hcf[i] = gcd(right_gcd[i], left_gcd[i]);
                if (hcf[i] >= key)
                {
                    bakra = (hcf[i] == key) ? MAX(bakra, a[i]) : a[i];
                    key = hcf[i];
                }
            }
            for (i = 0; i < n; i++)
            {
                if (a[i] == bakra)
                {
                    ans += 1;
                    bakra = -1;
                }
                else
                {
                    ans += a[i] / key;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
