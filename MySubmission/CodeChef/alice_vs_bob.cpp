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
lli powers_of_two[61] = {1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, t, ans, i;
    cin >> t;
    for (int i = 1; i < 61; i++)
    {
        powers_of_two[i] = powers_of_two[i - 1] * 2;
        // cout<<powers_of_two[i]<<" ";
    }
    while (t--)
    {
        cin >> n;
        ans = 0;
        while (n != 1)
        {
            if (n % 2 == 1)
            {
                n--;
                ans++;
            }
            for (i = 60; i >= 1; i--)
            {
                if (n == powers_of_two[i])
                {
                    ans += 1;
                    break;
                }
            }
            if (n == powers_of_two[i])
                break;

            for (i = 60; i >= 1; i--)
            {
                if (n % powers_of_two[i] == 0)
                {
                    n = n / powers_of_two[i];
                    ans++;
                    break;
                }
            }
        }
        if (ans % 2 == 0)
            // cout << "Alice " << ans << endl;
            cout << "Alice" << endl;
        else
            // cout << "Bob " << ans << endl;
            cout << "Bob" << endl;
    }
    return 0;
}