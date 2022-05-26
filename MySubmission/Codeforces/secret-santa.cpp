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
        lli n;
        cin >> n;
        lli a[n], b[n + 1] = {0}, i, j, fav = 0, ans[n] = {0};
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            if (b[a[i]] < n + 1)
            {
                fav++;
                ans[i] = a[i];
                b[a[i]] = n + 1;
                if (a[i] != i + 1)
                    b[i + 1] = i + 1;
            }
            else if (a[i] != i + 1)
                b[i + 1] = i + 1;
        }
        sort(b, b + (n + 1));
        for (i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n"
             << endl;
        j = 1;
        for (i = 0; i < n; i++)
        {
            if (ans[i] == 0)
            {
                ans[i] = b[j++];
            }
        }
        cout << fav << endl;
        for (i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}