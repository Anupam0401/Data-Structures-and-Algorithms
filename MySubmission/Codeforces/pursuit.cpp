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
        lli n, best, new_best, total_a = 0, total_b = 0, t;
        cin >> n;
        lli a[n], b[n], i, j, ans = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            total_a += a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            total_b += b[i];
        }
        best = n - n / 4;
        sort(a, a + n);
        sort(b, b + n);
        lli a_sum = 0, b_sum = 0;
        for (i = n - 1; i >= n - best; i--)
        {
            a_sum += a[i];
            b_sum += b[i];
        }
        cout << a_sum << " " << b_sum << "\n"
             << endl;
        if (a_sum >= b_sum)
            ans = 0;
        else
        {
            t = n;
            i = 0;
            while (a_sum < b_sum)
            {
                t++;
                new_best = t - t / 4;
                if (new_best > best)
                {
                    for (j = 1; j <= (new_best - best); j++)
                    {
                        a_sum += (n - best + i < n) ? 100 - a[n - best + i] : 100;
                        b_sum += (n - best - i >= 0) ? a[n - best + i] : 0;
                        i++;
                    }
                }
                else
                {
                    a_sum += (n - best + i < n) ? 100 - a[n - best + i] : 100;
                    i++;
                }
                cout << a_sum << " " << b_sum << endl;
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}