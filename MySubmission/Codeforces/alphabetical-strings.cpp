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

int indexOf_a(string s, char c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
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
        string str;
        cin >> str;
        int a[26] = {0}, i, n = str.size();
        bool flag = false;
        for (i = 0; i < n; i++)
        {
            a[str[i] - 'a'] += 1;
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] != 1)
            {
                // cout << "here87\n";
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            flag = true;
            int index = indexOf_a(str, 'a');
            for (i = index + 1; i < n; i++)
            {
                if (str[i] <= str[i - 1])
                {
                    // cout << "here100\n";
                    flag = false;
                    break;
                }
            }
            for (i = index - 1; i >= 0; i--)
            {
                if (str[i + 1] >= str[i])
                {
                    // cout << "here107\n";
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
