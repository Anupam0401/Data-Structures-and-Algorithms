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

long int min_distance_left(long int *a, long int dest)
{
    dest--;
    long int x = dest;
    while (x >= 0)
    {
        if (*(a + x) == 1)
            return (dest - x);
        x--;
    }
    return -1;
}

long int min_distance_right(long int *a, long int dest, long int n)
{
    dest--;
    long int x = dest;
    while (x < n)
    {
        if (*(a + x) == 2)
            return (x - dest);
        x++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int t;
    cin >> t;
    while (t--)
    {
        long int n, m;
        cin >> n >> m;
        long int a[n], b[m], i, c[m], x, y;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (i = 0; i < m; i++)
        {
            x = min_distance_left(a, b[i]);
            y = min_distance_right(a, b[i], n);
            if (x == -1 && y == -1)
                c[i] = -1;
            else if (x == -1 || y == -1)
                c[i] = MAX(x, y);
            else
                c[i] = MIN(x, y);
        }
        for (i = 0; i < m; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
    }
    return 0;
}