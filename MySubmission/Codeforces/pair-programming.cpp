#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
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
        int k, n, m;
        cin >> k >> n >> m;
        int mc[n], pc[m], i, c = n + m, j;
        for (i = 0; i < n; i++)
            cin >> mc[i];
        for (i = 0; i < m; i++)
            cin >> pc[i];

        vector<int> v;
        bool flag = true;
        i = 0;
        j = 0;
        while (c)
        {
            if (i < n and mc[i] == 0)
            {
                k++;
                i++;
                v.push_back(mc[i - 1]);
            }
            else if (j < m and pc[j] == 0)
            {
                k++;
                j++;
                v.push_back(pc[j - 1]);
            }
            else if (i < n and mc[i] != 0 and k >= mc[i])
            {
                i++;
                v.push_back(mc[i - 1]);
            }
            else if (j < m and pc[j] != 0 and k >= pc[j])
            {
                j++;
                v.push_back(pc[j - 1]);
            }
            else
            {
                flag = false;
                break;
            }
            c--;
            //printArray(vec,vec.size());
        }
        if (!flag)
        {
            cout << "-1\n";
        }
        else
        {
            for (i = 0; i < n + m; i++)
            {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
