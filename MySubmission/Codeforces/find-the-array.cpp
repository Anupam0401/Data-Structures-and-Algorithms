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
    // int store[5001] = {0};
    // int sume = 1, sumo = 0, counte = 1, counto = 0;
    // for (int p = 1; p <= 5000; p++)
    // {
    //     if (MAX(sume, sumo) > 5000)
    //         break;
    //     if (p & 1)
    //     {
    //         ++counto;
    //         sumo += p;
    //         store[sumo] = counto;
    //     }
    //     else
    //     {
    //         ++counte;
    //         sume += p;
    //         store[sume] = counte;
    //     }
    // }
    // for (int p = 1; p <= 5000; p++)
    //     cout << store[p] << " ";
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        if (s == 1)
            cout << "1\n";
        else if (s == 2)
            cout << "2\n";
        else
        {
            int ans = 0, minus = 1;
            while (s > 1)
            {
                s -= minus;
                ans++;
                minus += 2;
            }
            if (s == 1)
                cout << ans + 1 << "\n";
            else
                cout << ans << "\n";
        }
    }

    return 0;
}